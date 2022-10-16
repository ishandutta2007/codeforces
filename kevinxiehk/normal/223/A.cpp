#include <bits/stdc++.h>
#define mp make_pair
#define pb emplace_back
#define fi first
#define se second
#define int long long
#define inf 1e18
using namespace std;
const int maxn = 1000005; // REMEMBER TO CHANGE UPPER BOUND
int mod = 1000000007, mod2 = 998244353, n, fac[maxn + 5], invfac[maxn + 5], arr[maxn + 5];
void mod998() {swap(mod, mod2);}
bool isprime(int k) {
    for(int i = 2; i * i <= k; i++) if(k % i == 0) return false; 
    return true;
}
int bm(int a, int b) {
    if(b == 0) return 1; 
    int t = bm(a, b / 2); 
    return (b % 2 == 1 ? t * t % mod * a % mod : t * t % mod);
}
int inv(int a) {return bm(a, mod - 2);}
int ncr(int n, int r) {
    return (r > n ? 0LL : fac[n] * invfac[r] % mod * invfac[n - r] % mod);
}
void pre_fac(int n) {
    fac[0] = 1; for(int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
}
void pre_invfac(int n) {
    for(int i = 0; i <= n; i++) invfac[i] = inv(fac[i]);
}

int fen[100005];
void add(int id) {
    id++;
    while(id <= n) {
        fen[id]++;
        id += (id & -id);
    }
}
int sum(int id) {
    id++;
    int a = 0;
    while(id > 0) {
        a += fen[id];
        id -= (id & -id);
    }
    return a;
}

void solve(int TC) {
    // cin >> n;
    // for(int i = 1; i <= n; i++) cin >> arr[i]; // 1 BASED!!
    string s;
    cin >> s;
    n = s.length();
    stack<pair<char, int>> aaa;
    int ans = 0;
    int anst = 0;
    int anen = -1;
    int st = 0, len = 0;
    int tc = 0;
    int lap = inf;
    int enn = -1;
    int idk = 0;
    vector<int> pp;

    for(int i = 0; i < n; i++) {
        bool die = false;
        if(s[i] == '[') {
            aaa.push(mp(s[i], i));
            tc++;
            pp.pb(i);
            add(i);
        }
        else if(s[i] == '(') {
            aaa.push(mp(s[i], i));
            pp.pb(i);
        }
        else if(s[i] == ')') {
            if(aaa.empty() || aaa.top().fi != '(') die = true;
            else {
                lap = min(lap, aaa.top().se);
                aaa.pop();
                enn = max(enn, i);
                // cout << i << '\n';
                int asd;
                if(!aaa.empty()) asd = max(idk, aaa.top().se + 1);
                else asd = idk;
                int ta = sum(i) - sum(asd - 1);
                if(ta > ans) {
                    ans = ta;
                    anst = asd;
                    anen = i;
                }
            }
        }   
        else {
            if(aaa.empty() || aaa.top().fi != '[') die = true;
            else {
                // lap = aaa.top().se;
                lap = min(lap, aaa.top().se);
                aaa.pop();
                enn = max(enn, i);
                // cout << i << '\n';
                int asd;
                if(!aaa.empty()) asd = max(idk, aaa.top().se + 1);
                else asd = idk;
                int ta = sum(i) - sum(asd - 1);
                if(ta > ans) {
                    ans = ta;
                    anst = asd;
                    anen = i;
                }
            }
        }
        if(die) {
            tc = 0;
            while(!aaa.empty()) aaa.pop();
            st = i + 1;
            lap = inf;
            enn = -1;
            idk = i + 1;
        }
        else if(aaa.empty()) {
            if(tc > ans) {
                ans = tc;
                anst = st;
                anen = i;
            }
        }
        else if(i == n - 1) {
            
            int tt = lap;
            int aaaaaa = aaa.top().se;
            while(!aaa.empty()) {
                if(aaa.top().se > tt) enn = min(enn, aaa.top().se - 1);
                if(aaa.top().fi == '[') tc--;
                aaa.pop();
            }
            if(tc > ans) {
                ans = tc;
                anst = tt;
                anen = enn;
            }
        }
    }

    // wtf

    // ???????????????????????????????
    // g
    // how to handle this??
    //wtf tc 16
    cout << ans << '\n';
    for(int i = anst; i <= anen; i++) cout << s[i]; cout << '\n';
}
signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;  
    // cin >> t; // REMOVE THIS LINE IF ONLY 1 CASE
    for(int i = 1; i <= t; i++) solve(i);
}