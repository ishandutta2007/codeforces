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
typedef complex<short> pt;
#define X real()
#define Y imag()
const pt dir4[] = {{1,0},{0,1},{-1,0},{0,-1}};
const pt dir8[] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
const pt hdir[] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
bool inside(pt p) {
    return 0<=p.X and p.X<10 and 0<=p.Y and p.Y<10;
}
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
int main() {
    vector<string> g(10);
    for(auto & i : g) cin >> i;
    for(int i=0;i<10;++i) {
        for(int j=0;j<10;++j) if(g[i][j]=='.') {
            pt o = {i,j};
            int cnt[8] = {};
            int id=0;
            for(auto d : dir8) {
                pt at = o+d;
                while(inside(at) and g[at.X][at.Y]=='X') {
                    cnt[id]++, at+=d;
                }
                if(cnt[id] + cnt[(id+4)%8]>=4) {
                    cout << "YES\n";
                    exit(0);
                }
                id++;
            }
        }
    }
    cout << "NO\n";
}