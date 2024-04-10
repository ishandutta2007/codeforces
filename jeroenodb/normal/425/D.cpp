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
auto cross(pt u, pt v) {return (ll)u.X*v.Y-(ll)u.Y*v.X;}
auto sgn(ll a) {return a==0?0:(a>0?1:-1);}
auto ccw(pt p1, pt p2, pt p3) {auto u = p2-p1, v = p3-p2;return cross(u,v);}
auto in(pt p1, pt p2) {return (ll)p1.X*p2.X+(ll)p1.Y*p2.Y;}
auto norm(pt p) {return (ll)p.X*p.X+(ll)p.Y*p.Y;}
bool comp(const pt& a, const pt& b) { return a.X<b.X or (a.X==b.X and a.Y < b.Y);}
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
const int B = 280;
int main() {
    int n; cin >> n;
    vector<pt> pts(n);
    int mxY=0;
    for(auto& i : pts) read(i),mxY=max(mxY,i.Y);
    sort(all(pts),comp);
    auto exists=[&](pt p, int hint=0) {
        return binary_search(hint+all(pts),p,comp);
    };
    int ans=0;
    vector<bool> vis(mxY+1);
    for(int i=0,j=1;i<n;i=j) {
        while(j<n and pts[i].X==pts[j].X) ++j;
        for(int k=i;k<j;++k) vis[pts[k].Y]=true;
        if(j-i>=B) {
            for(int k=j;k<n;++k) {
                int side = pts[k].X-pts[i].X;
                if(side+pts[k].Y>mxY) continue;
                if(vis[pts[k].Y] and vis[pts[k].Y+side] and exists(pts[k]+pt{0,side},k)) {
                    ++ans;
                }
            }
        } else {
            for(int k=i;k<j;++k) {
                for(int o=k+1;o<j;++o) {
                    int side = pts[o].Y-pts[k].Y;
                    assert(side>0);
                    if(exists(pts[k]+pt{side,0},j) and exists(pts[o]+pt{side,0},j)) {
                        ans++;
                    }
                }
            }
        }
        for(int k=i;k<j;++k) vis[pts[k].Y]=false;
    }
    cout << ans;
}