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
typedef complex<int> pt;
#define X real()
#define Y imag()
const pt dir4[] = {{1,0},{0,1},{-1,0},{0,-1}};
const pt dir8[] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const pt hdir[] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
int dist(pt p) {
    return abs(p.X)+abs(p.Y);
}
int main() {
    int t; cin >> t;
    while(t--) {
        int n,m; cin >> n >> m;
        pt corners[] = {{0,0},{0,m-1},{n-1,0},{n-1,m-1}};
        vi options;
        for(int i=0;i<n;++i) for(int j=0;j<m;++j) {
            pt p = {i,j};
            int worst = 0;
            for(auto q : corners) {
                worst = max(dist(q-p),worst);
            }
            options.push_back(worst);
        }
        sort(all(options));
        cout << options << '\n';
    }
}