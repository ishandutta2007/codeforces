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
const int mxN = 4e5, oo = 1e9;
typedef complex<double> pt;
#define X real()
#define Y imag()
auto cross(pt u, pt v) {return (ll)u.X*v.Y-(ll)u.Y*v.X;}
auto sgn(ll a) {return a==0?0:(a>0?1:-1);}
auto ccw(pt p1, pt p2, pt p3) {auto u = p2-p1, v = p3-p2;return cross(u,v);}
auto in(pt p1, pt p2) {return p1.X*p2.X+p1.Y*p2.Y;}
auto norm(pt p) {return p.X*p.X+p.Y*p.Y;}
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}

struct event {
    double angle;
    int id;
    bool end;
    bool operator<(const event& o) {
        return angle<o.angle or (angle==o.angle and end < o.end);
    }
};
const double tau = 2*acos(-1);
vector<pt> pts;
vector<double> lowerbound;
pt ans = {-1,-1};
double best = oo;
int n,k;
bool solve(double denom, double r) {
    bool good = false;
    pt a = {0,0};
    vector<event> events;
    for(int j=0;j<n;++j) {
        pt b = pts[j];
        pt v = b-a;
        if(abs(v)>=2*r-1e-8) continue;
        double delta = acos(abs(v)*denom);
        double angle = arg(v);
        events.push_back({angle-delta,j,false});
        auto& e1 = events.back();
        while(e1.angle<0) 
            e1.angle+=tau;
        while(e1.angle>=tau) 
            e1.angle-=tau;
        events.push_back({angle+delta,j,true});
        auto& e2 = events.back();
        while(e2.angle<0) 
            e2.angle+=tau;
        while(e2.angle>=tau) 
            e2.angle-=tau;
    }
    sort(all(events));
    bitset<mxN> visited;
    int overlap=0;
    for(auto& e : events) {
        if(e.end) {
            if(visited[e.id]) overlap--;
        } else {
            visited[e.id] = true;
            overlap++;
        }
    }
    for(auto& e : events) {
        if(e.end) {
            overlap--;
        } else {
            overlap++;
        } 
        if(overlap>=k) {
            best = r;
            ans = a + polar(r,e.angle);
            good = true;
            break;
        }
    }
    return good;
}
int main() {
    cin >> n >> k;
    pts.resize(n);
    double lo = 0.00000001, hi =0.5;
    for(auto& p:pts) {
        read(p);
        hi = max(hi,abs(p));
    }
    hi+=1;

    while(hi-lo>1e-5) {
        double mid = 0.5*(hi+lo);
        double denom = 0.5/mid;
        if (solve(denom,mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << setprecision(8) << 0.5*(hi+lo) << '\n';

}