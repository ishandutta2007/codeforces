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
    int n,pos,l,r; cin >> n >> pos >> l >> r;
    int ans =0;
    if(l==1 and r==n) ans=0;
    else if(l==1) ans = abs(r-pos);
    else if(r==n) ans = abs(l-pos);
    else {
        ans = min(abs(l-pos),abs(r-pos))+r-l;
    }
    if(l>1) ans++;
    if(r<n) ans++;
    cout << ans << '\n';
}