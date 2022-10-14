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
    int n,q; cin >> n >> q;
    string s; cin >> s;
    s.push_back('$');
    vi p0(n+1),p1(n+1);
    for(int i=1;i<=n;++i) {
        if(s[i]==s[i-1]) {
            if(s[i]=='0') {
                p0[i]++;
            } else p1[i]++;
        }
        p0[i]+=p0[i-1];
        p1[i]+=p1[i-1];
    }
    while(q--) {
        int l,r; cin >> l >> r;
        --r,--l;
        cout << max(p1[r]-p1[l],p0[r]-p0[l])+1 << '\n';
    }

}