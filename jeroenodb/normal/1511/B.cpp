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
    int t; cin >> t;
    ll power[10];
    power[0] = 1;
    for(int i=1;i<10;++i) {
        power[i] = 10*power[i-1];
    }
    while(t--) {
        int a,b,c; cin >> a >> b >> c;
        if(a>b) {
               cout << power[a-1]+power[c-1] << ' ' << power[b-1] << '\n';
        } else cout << power[a-1] << ' ' << power[b-1]+power[c-1] << '\n';
    }
}