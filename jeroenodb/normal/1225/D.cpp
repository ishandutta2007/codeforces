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
const int store=1e6 + 1;
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
int k;
pair<ll,ll> getSketch(int a) {
    ll invert=1,res=1;
    while(a!=1) {
        int f = factor[a],tmp=0;
        while(a%f==0) a/=f,tmp++;
        tmp%=k;
        for(int i=0;i<tmp;++i) res*=f;
        int o = (k-tmp)%k;
        for(int i=0;i<o;++i) if(invert<=mxN) {
            invert*=f;
        }
    }
    return {res,invert};
}

int main() {
    makesieve();
    int n; cin >> n >> k;
    map<ll,int> cnt;
    ll ans=0;
    for(int i=0;i<n;++i) {
        int a; cin >> a;
        auto [cur,inv] = getSketch(a);
        if(inv<=mxN) {
            ans+=cnt[inv];
        }
        cnt[cur]++;
    }
    cout << ans << '\n';

}