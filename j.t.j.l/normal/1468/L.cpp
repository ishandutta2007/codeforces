#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

ll gcd(ll p, ll q) {
    return q ? gcd(q, p % q) : p;
}

ll Rrand() {
    ll x = rand();
    return ((((x << 16) | rand()) << 16) | rand());
}

class Primality {
public:
    typedef long long LL;
    const int N = 1000000;
    vector<int> pm, vis;
    bool miller_rabin(LL num){
        if(num<=1) return false;
        if(num<=3) return true;
        if(~num&1) return false;
		const int u[]={2,3,5,7,11,13,17,19,23,29,0};
        LL e=num-1,a,c=0;
        while(~e&1) e/=2,c++;
        for(int i=0;u[i];i++){
            if(num<=u[i]) return true;
            a=POW(u[i],e,num);
            if(a==1) continue;
            for(int j=1;a!=num-1;j++){
                if(j==c) return false;
                a=MUL(a,a,num);
            }
        }
        return true;
    }
    LL pollard_rho(LL n){
        if(n<=3 || miller_rabin(n)) return n;
        while(1){
            int i=1,cnt=2;
            LL x=Rrand()%n,y=x,c=Rrand()%n;
            if(!c || c==n-2) c++;
            do{
                LL u=gcd(n-x+y,n);
                if(u>1 && u<n) return u;
                if(++i==cnt) y=x,cnt*=2;
                x=(c+MUL(x,x,n))%n;
            }while(x!=y);
        }
        return n;
    }
    vector<PLL> factorize(LL n){
        vector<PLL> res;
        for (int i = 0, j; i < pm.size() && (j = pm[i]) <= n; i++) {
            if (n % j == 0) {
                int cnt = 0;
                while (n % j == 0) {
                    cnt++;
                    n = n / j;
                }
                res.emplace_back((LL)j, (LL)cnt);
            }
        }
        vector<LL> u;
        if(n>1) u.push_back(n);
        for(size_t i=0;i<u.size();i++){
            LL x=pollard_rho(u[i]);
            if(x==u[i]) continue;
            u[i--]/=x;
            u.push_back(x);
        }
        sort(u.begin(),u.end());
        for (int i = 0; i < u.size();) {
            int j = i;
            while (j < u.size() && u[j] == u[i]) j++;
            res.emplace_back(u[i], j - i);
            i = j;
        }
        return res;
    }
	LL MUL(LL a, LL b, LL mod) {
		if (mod < int(1e9)) return a * b % mod;
		LL k = (LL)((long double)a * b / mod);
		LL res = a * b - k * mod;
		res %= mod;
		if (res < 0) res += mod;
		return res;
	}
    LL POW(LL x, LL y, LL m){
        LL c,s=1;
        for(c=x%m;y;c=MUL(c,c,m),y>>=1)
            if(y&1) s=MUL(s,c,m);
        return s;
    }
    void init() {
        pm.clear();
        vis.assign(N + 10, 0);
        vis[0] = vis[1] = 1;
        for (int i = 2; i <= N; ) {
            pm.push_back(i);
            for (int j = i + i; j <= N; j += i) vis[j] = 1;
            i++;
            while (i <= N && vis[i]) i++;
        }
    }
    int cmp_pw(ll x, ll i, ll n) {
        ll y = x;
        for (int j = 2; j <= i; j++) {
            if (y <= n / x) {
                y *= x;
            }
            else return 1;
        }
        if (y == n) return 0;
        else return -1;
    }
    int lazy_factorize(vector<PLL>& f, ll n) {
        for (int i = 60; i >= 3; i--) {
            ll x = exp(log(n) / i);
            int tmp = cmp_pw(x, i, n);
            while (tmp == -1) tmp = cmp_pw(++x, i, n);
            while (tmp == 1) tmp = cmp_pw(--x, i, n);
            if (tmp == 0) {
                if (vis[x] == 0) {
                    f.emplace_back((ll)x, (ll)i);
                    return 1;
                }
                else {
                    return 0;
                }
            }
        }
        for (int i = 2; i >= 2; i--) {
            ll x = exp(log(n) / i);
            int tmp = cmp_pw(x, i, n);
            while (tmp == -1) tmp = cmp_pw(++x, i, n);
            while (tmp == 1) tmp = cmp_pw(--x, i, n);
            if (tmp == 0) {
                if (miller_rabin(x)) {
                    f.emplace_back((ll)x, (ll)i);
                    return 1;
                }
                else {
                    return 0;
                }
            }
        }
        if (miller_rabin(n)) {
            f.emplace_back((ll)n, (ll)1);
            return 1;
        }
        return 0;
    }
} nico;

int n, k;
vector<PLL> f[1010];
ll g[1010];
int ty[1010];
map<ll, vector<int>> pm;
map<ll, ll> valid_pm;

void solve(int casi){
    scanf("%d%d", &n, &k);
    nico.init();
    pm.clear();
    for (int i = 0; i < n; i++) {
        scanf("%lld", &g[i]);
        int ppwf = nico.lazy_factorize(f[i], g[i]);
        // f[i] = nico.factorize(g[i]);
        if (ppwf) {
            pm[f[i][0].first].push_back(i);
            ty[i] = 1;
        }
        else ty[i] = 0;
    }
    if (k == 1) {
        puts("0");
        return ;
    }
    valid_pm.clear();
    int bs = 0;
    int has_more_than_2 = 0;
    for (auto &x : pm) {
        if (x.second.size() > 1) {
            valid_pm[x.first] = x.second.size();
            bs += 2;
            if (x.second.size() > 2) {
                has_more_than_2 = x.first;
            }
        }
    }
    vector<ll> ans;
    if (bs <= k) {
        for (auto &x : pm) {
            if (x.second.size() > 1) {
                for (int i = 0; i < 2; i++) 
                    ans.emplace_back(g[x.second[i]]);
            }
        }
        for (auto &x : pm) {
            if (x.second.size() > 1) {
                for (int i = 2; i < x.second.size() && bs < k; i++) {
                    ans.emplace_back(g[x.second[i]]);
                    bs++;
                }
            }
        }
        for (int i = 0; i < n && bs < k; i++) {
            if (ty[i] == 0) {
                bool valid = true;
                ll gg = g[i];
                for (auto &x : valid_pm) {
                    while (gg % x.first == 0) {
                        gg /= x.first;
                    }
                    if (gg == 1) break;
                }
                if (gg == 1) {
                    bs++;
                    ans.push_back(g[i]);
                }
            }
        }
    }
    else {
        // bs > k
        int cur = 0;
        if (k % 2 == 0 || has_more_than_2) {
            if (k % 2 == 1) {
                for (int i = 0; i <= 2; i++) {
                    cur++;
                    ans.push_back(g[pm[has_more_than_2][i]]);
                }
            } else has_more_than_2 = 0;
            for (auto &x : pm) {
                if (x.second.size() > 1 && x.first != has_more_than_2 && cur < k) {
                    for (int i = 0; i < 2 && cur < k; i++) {
                        ans.emplace_back(g[x.second[i]]);
                        cur++;
                    } 
                }
            }
        }
        else {
            int magic = -1;
            for (int i = 0; i < n; i++) {
                if (ty[i] == 0) {
                    ll gg = g[i];
                    for (auto &x : valid_pm) {
                        if (gg % x.first == 0) {
                            ll cnt = 0;
                            while (gg % x.first == 0) {
                                cnt++;
                                gg /= x.first;
                            }
                            f[i].emplace_back(x.first, cnt);
                        }
                        if (gg == 1) break;
                    }
                    if (gg == 1 && f[i].size() <= k / 2) {
                        magic = i;
                        break;
                    }
                }
            }
            // cout << "???" << magic << endl;
            if (magic >= 0) {
                set<ll> used_pm;
                for (auto &x : f[magic]) {
                    used_pm.insert(x.first);
                    for (int i = 0; i < 2; i++) {
                        cur++;
                        ans.emplace_back(g[pm[x.first][i]]);
                    }
                }
                ans.emplace_back(g[magic]);
                cur++;
                for (auto &x : pm) {
                    if (cur < k && x.second.size() > 1 && used_pm.find(x.first) == used_pm.end()) {
                        for (int i = 0; i < 2; i++) {
                            cur++;
                            ans.emplace_back(g[x.second[i]]);
                        }
                    }
                }
            }
        }
    }
    if (ans.size() != k) {
        puts("0");
    }
    else {
        for (int i = 0; i < k; i++) {
            printf("%lld%c", ans[i], " \n"[i + 1 == k]);
        }
    }
}

int main(){
    int T = 1;
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}