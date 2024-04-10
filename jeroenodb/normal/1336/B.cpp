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
const int mxN = 1e5+1;
const ll oo = 8e18;
ll sq(int a) {
    return (ll)a*a;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        ll ans = oo;
        int n[3];
        for(auto& i : n) cin >> i;
        vi vv[3];
        for(int rep=0;rep<3;++rep) {
            auto& v = vv[rep];
            v.resize(n[rep]);
            for(auto& i : v) cin >> i;
            sort(all(v));
        }
        array<int,3> order = {0,1,2};
        do {
            array<vi::iterator,3> s,e;
            for(int i=0;i<3;++i) {
                s[i] = vv[order[i]].begin();
                e[i] = vv[order[i]].end();
            }
            while(s[1]!=e[1]) {
                while(next(s[0])!=e[0] and *next(s[0]) <= *s[1]) s[0]++;
                while(*s[2]<*s[1]) {
                    s[2]++;
                    if(s[2]==e[2]) goto end;
                }
                ans = min(ans, sq(*s[0]-*s[1])+sq(*s[2]-*s[1])+sq(*s[0]-*s[2]));
                ++s[1];
            }
            end: ans=ans;
        } while(next_permutation(all(order)));
        cout << ans << '\n';
    }
}