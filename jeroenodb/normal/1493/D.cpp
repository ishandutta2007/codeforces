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

const int store=2e5 + 1;
bitset<store> sieve={};
int factor[store] = {};
void makesieve() {
    for(int i = 2; i < store;++i) {
        if(!sieve[i]) {
            for(int j = i;j<store;j+=i) {
                if(!sieve[j]) {
                    factor[j] = i;
                    sieve[j] = true;
                }
            }
        }
    }
}


const long long MOD = 1e9+7;
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
};
mint& operator+=(mint& a, const mint& o) {
    a.d+=o.d;
    if(a.d>=MOD) a.d-=MOD;
    return a;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    makesieve();
    int n,q; cin >> n >> q;
    map<int,map<int,int>> m;
    vector<map<int,int>> a(n);
    int gcd = -1;
    for(int i=0;i<n;++i) {
        int b; cin >> b;
        if(gcd==-1) {
            gcd = b;
        } else {
            gcd = __gcd(gcd,b);
        }

        while(b!=1) {
            int f = factor[b];
            int cnt = a[i][f]++;
            m[f][cnt+1]++;
            b/=f;
        }
    }
    mint mgcd = gcd;
    while(q--) {
        int i,x; cin >> i >> x;--i;

        while(x!=1) {
            int f = factor[x];
            int cnt = a[i][f]++;;

            if(++m[f][cnt+1]==n) {
                mgcd = mgcd*f;
            }

            x/=f;
        }
        cout << mgcd.d << '\n';
    }

}