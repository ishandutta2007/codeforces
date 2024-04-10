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
int cnt=0;
vector<pi> ans;
void solve(vi d) {
    if(d.size()==0) {
        cnt++;
        return;
    }
    if(d.size()==1) {
        cnt+=d[0]+1;
        for(int i=0;i<d[0]+1;++i) {
            for(int j=0;j<i;++j) {
                ans.emplace_back(i,j);
            }
        }
        return;
    }
    vi od;
    for(int i=1;i<d.size()-1;++i) {
        od.push_back(d[i]-d[0]);
    }
    solve(od);
    cnt+=d.back()-d.end()[-2];
    int last=cnt+d[0];
    while(cnt!=last) {
        for(int i=0;i<cnt;++i) {
            ans.emplace_back(i,cnt);
        }
        cnt++;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vi d(n);
    for(auto& i : d) cin >> i;
    solve(d);
    cout << ans.size() << '\n';
    // vi deg(d.back()+1);
    // for(auto [a,b]:ans) deg[a]++,deg[b]++;
    // set<int> s(all(deg));
    // debug(s);

    for(auto [a,b]:ans) cout << a+1 << ' ' << b+1 << '\n';
}