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
auto ccw(pt p1, pt p2, pt p3) {auto u = p2-p1, v = p3-p1;return cross(u,v);}
auto in(pt p1, pt p2) {return (ll)p1.X*p2.X+(ll)p1.Y*p2.Y;}
auto norm(pt p) {return (ll)p.X*p.X+(ll)p.Y*p.Y;}
bool comp(const pt& a, const pt& b) { return a.X<b.X or (a.X==b.X and a.Y < b.Y);}
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<class I> I rnd(I l,I r){return std::uniform_int_distribution<I>(l,r)(rng);}
void yes() {cout << "YES\n"; exit(0);}
void no() {cout << "NO\n"; exit(0);}
int main() {
    int n; cin >> n;
    vector<pt> pts(n);
    for(auto& i : pts) read(i);
    if(n==1) yes();
    for(int rep=0;rep<50;++rep) {
        int i=rnd(0,n-1), j;
        do {
            j = rnd(0,n-1);
        } while(i==j);
        vector<pt> left;
        for(auto p : pts) {
            if(ccw(p,pts[i],pts[j])!=0) left.push_back(p);
        }
        if(left.size()<2) yes();
        bool bad=false;
        for(auto p : left) {
            if(ccw(left[0],left[1],p)!=0) {
                bad=true;
                break;
            }
        }
        if(!bad) yes();
    }
    no();

}