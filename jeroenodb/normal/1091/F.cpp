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
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    ll stamina=0,res=0;
    bool haveWater=false;
    vector<ll> l(n); for(auto& i : l) cin >> i;
    string s; cin >> s;
    vector<ll> suf(n,ll(1e18)),mystam(n);
    for(int i=0;i<n;++i) {
        auto curl = l[i];
        mystam[i]=stamina;
        if(s[i]=='W') haveWater=true;
        if(s[i]=='L') {
            if(stamina<curl) {
                res+=(haveWater?3:5)*(curl-stamina);
                stamina=curl;
            }
            stamina-=curl;
            suf[i]=stamina;
            res+=curl;
        } else {
            stamina+=curl;
            if(s[i]=='W') {
                res+=3*curl;
            } else res+=5*curl;
        }
    }
    suf[n-1] = stamina;
    for(int i=n-2;i>=0;--i) suf[i] = min(suf[i],suf[i+1]);
    ll missedStamina=0;
    // pick as much grass as possible
    // everything times 2
    for(int i=0;i<n;++i) {
        if(s[i]=='G') {
            ll use = clamp(2*l[i], 0LL, min(l[i]+mystam[i]-missedStamina, (suf[i]-missedStamina)));
            res-=2*use;
            missedStamina+=use;
        }
    }
    res-=(stamina-missedStamina);
    cout << res << '\n';

}