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
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
struct rect {
    pt p, q;
};
vector<rect> rs;
bool rec(vi ids) {
    if(ids.size()==1) return true;
    sort(all(ids), [&](int a,int b){
        return rs[a].p.X<rs[b].p.X;
    });
    int mx=-oo;
    int n = ids.size();
    for(int i=0;i<n;++i) {
        if(rs[ids[i]].p.X>=mx and i) {
            // cut here
            return rec(vi(ids.begin(),ids.begin()+i)) and rec(vi(ids.begin()+i,ids.end()));
        }
        mx=max(mx,rs[ids[i]].q.X);
    }
    sort(all(ids), [&](int a,int b){
        return rs[a].p.Y<rs[b].p.Y;
    });
    mx=-oo;
    for(int i=0;i<n;++i) {
        if(rs[ids[i]].p.Y>=mx and i) {
            // cut here
            return rec(vi(ids.begin(),ids.begin()+i)) and rec(vi(ids.begin()+i,ids.end()));
        }
        mx=max(mx,rs[ids[i]].q.Y);
    }
    return false;
}
int main() {
    int n; cin >> n;
    rs.resize(n);
    for(auto& r : rs) {
        read(r.p);
        read(r.q);
    }
    vi v(n); iota(all(v),0);
    cout << (rec(v)?"YES\n":"NO\n");
}