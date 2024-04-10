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
void solve() {
    int n,m; cin >> n >> m;
    vi a(m); for(auto& i : a) cin >> i;
    sort(all(a));
    
    priority_queue<int> gaps;
    gaps.push(a[0]+n-a.back()-1);
    for(int i=0;i+1<m;++i) {
        gaps.push(a[i+1]-a[i]-1);
    }
    int t=0;
    int saved=0;
    while(!gaps.empty()) {
        auto g = gaps.top();
        g-=2*t;
        gaps.pop();
        if(g<=0) continue;
        if(g==1 or g==2) {
            saved++;
            t++;
        } else {
            saved+=g-1;
            t+=2;
        }
    }
    cout << n-saved<< '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}