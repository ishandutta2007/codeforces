#pragma GCC optimize "Ofast"
#include <iostream>
#include <vector>
#include <bitset>
#include <cassert>
#include <algorithm>
using namespace std;
#define all(x) begin(x),end(x)
typedef long long ll;
const int mxN = 1e5+1;
const long long MOD = 1e9 + 7, halve = 1 + MOD/2;
class mint {
public:
    long long d;
    mint (long long _d) : d(_d%MOD){};
    mint() {}
    mint operator*(const mint& o) const {
        return (d*o.d)%MOD;
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
};
ostream& operator<<(ostream& c, mint a) {return  c << a.d;}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    mint power[60] = {};
    power[0] = 1;
    for(int i=1;i<60;++i) {
        power[i] = power[i-1]+power[i-1];
    }
    while(t--) {
        int n; cin >> n;
        mint ans = 0;
        vector<ll> a(n);
        int cnt[60] = {};
        mint som = 0;
        for(int i=0;i<n;++i) {
            cin >> a[i];
            for(int j=0;j<60;++j) {
                if(a[i]&(1LL<<j)) {
                    cnt[j]++;
                }
            }
            som = som + a[i];
        }
        for(auto x: a) {
            ll ors = 0;
            for(int i=0;i<60;++i) {
                if(x & (1LL<<i)) {
                    ors = ors + power[i].d*n;
                } else {
                    ors = ors + power[i].d*cnt[i];
                }
            }
            mint mors = ors;
            ans = ans + mors*((mint)x*n + som-mors);
        }
        cout << ans << endl;
    }
}