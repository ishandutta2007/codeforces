#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
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
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<pt> pts(n);
    for(auto& p : pts) read(p);
    struct seg {
        int i,j;
        ll d;
        bool operator<(const seg& o) {
            return d > o.d;
        }
    };
    vector<seg> segments;
    segments.reserve(n*(n-1)/2);
    for(int i=0;i<n;++i) {
        for(int j=i+1;j<n;++j) {
            segments.push_back({i,j,norm(pts[i]-pts[j])});
        }
    }
    vector<bool> visited(n);
    sort(all(segments));
    bool begin=true;
    vi ans;
    for(auto& s: segments) {
        if(begin) {
            ans.push_back(s.i);
            ans.push_back(s.j);
        }
        if (visited[s.i] or visited[s.j]) 
            continue;
        visited[s.i] = visited[s.j] = true;
        if(begin) {
            begin = false;
            continue;
        }
        auto& plast = pts[ans.back()];
        if(in( pts[s.j]-plast,pts[s.i]- pts[s.j]) < 0) {
            swap(s.i,s.j);
        }
        auto& p1 = pts[s.i], &p2 = pts[s.j];
        // assert(in(p1-plast,p2-p1)<0);
        ans.push_back(s.i);
        ans.push_back(s.j);
    }
    assert(ans.size()+1>=n);
    for(int i=0;i<n;++i) {
        if(!visited[i]) {
            ans.push_back(i);
            break;
        }
    }
    for(int i: ans) cout << i+1 << ' ';
    cout << endl;
}