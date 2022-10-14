#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
ll seed;
int n,m,vmax;
ll rnd() {
    ll ret = seed;
    seed = (seed * 7 + 13)% 1000000007;
    return ret;
}

long long MOD = 1e9+7;
class mint {
public:
    int d;
    mint () {d=0;}
    mint (long long _d) : d(_d%MOD){};
    mint operator*(const mint& o) const {
        return ((ll)d*o.d)%MOD;
    }
    mint operator+(const mint& o) const {
        long long tmp = d+o.d;
        if(tmp>=MOD) tmp-=MOD;
        return tmp;
    }
    mint operator-(const mint& o) const {
        long long tmp = d-o.d;
        if(tmp<0) tmp+=MOD;
        return tmp;
    }
    mint operator^(long long b) const {
        mint tmp = 1;
        mint power = *this;
        while(b) {
            if(b&1) {
                tmp = tmp*power;
            }
            power = power*power;
            b/=2;
        }
        return tmp;
    }
    mint operator/(const mint& o) {
        return *this * (o^(MOD-2));
    }
    bool operator==(const mint& o) {
        return d==o.d;
    }
    friend mint& operator+=(mint& a, const mint& o) {
        a.d+=o.d;
        if(a.d>=MOD) a.d-=MOD;
        return a;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> seed >> vmax;
    struct iv {
        ll v;
        int r;
    };
    map<int,ll> mp;
    for(int i=1;i<=n;++i) {
        mp[i] = (rnd() % vmax) + 1;
    }
    mp[n+1]=0;

    for(int i=1;i<=m;++i) {

        int op = (rnd() % 4) + 1;
        int l = (rnd() % n) + 1;
        int r = (rnd() % n) + 1;
        if (l > r) swap(l, r);
        int x,y=-1;
        if (op == 3) x = (rnd() % (r - l + 1)) + 1;
        else x = (rnd() % vmax) + 1;
        if (op == 4) y = (rnd() % vmax) + 1;
        auto cut = [&](int k) {
            auto f = mp.lower_bound(k);
            if(f==mp.end() or f->first!=k) {
                auto p = prev(f);
                mp[k] = p->second;
            }
        };
        // debug(op);
        // debug(l);
        // debug(r);
        cut(l);
        cut(r+1);
        auto a = mp.find(l), b = mp.find(r+1);
        if(op==1) {
            while(a!=b) {
                a->second+=x;
                a++;
            }
        } else if(op==2) {
            auto beg = a;
            ++a;
            while(a!=b) {
                a = mp.erase(a);
            }
            beg->second=x;
        } else if(op==3) {
            vector<pair<ll,int>> v;
            while(a!=b) {
                v.push_back({a->second,next(a)->first-a->first});
                ++a;
            }
            sort(all(v));
            int cnt=0;
            for(auto& [val,times] : v) {
                cnt+=times;
                if(cnt>=x) {
                    cout << val << '\n';
                    break;
                }
            }
        } else {
            MOD=y;
            mint ans=0;
            while(a!=b) {
                ans+= (mint(a->second)^x) * (next(a)->first-a->first);
                a++;
            }
            cout << ans.d << '\n';
        }
    }
}