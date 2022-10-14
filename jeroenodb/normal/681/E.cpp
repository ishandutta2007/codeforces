#include "bits/stdc++.h"
using namespace std;
#define all(x) begin(x),end(x)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { string sep; for (const T &x : v) os << sep << x, sep = " "; return os; }
#define debug(a) cerr << "(" << #a << ": " << a << ")\n";
typedef __int128_t ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
const int mxN = 1e5+1, oo = 1e9;
typedef complex<double> pt;
#define X real()
#define Y imag()
auto cross(pt u, pt v) {return (ll)u.X*v.Y-(ll)u.Y*v.X;}
auto sgn(ll a) {return a==0?0:(a>0?1:-1);}
auto ccw(pt p1, pt p2, pt p3) {auto u = p2-p1, v = p3-p1;return cross(u,v);}
auto in(pt p1, pt p2) {return (ll)p1.X*p2.X+(ll)p1.Y*p2.Y;}
auto mnorm(pt p) {return (ll)p.X*(ll)p.X+(ll)p.Y*(ll)p.Y;}
bool comp(const pt& a, const pt& b) { return a.X<b.X or (a.X==b.X and a.Y < b.Y);}
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
typedef pt P;
const double tau = 2*3.14159265359;
int main() {
    pt p; read(p);
    double v,T; cin >> v >> T;
    T*=v;
    int n; cin >> n;
    vector<pair<pt,long long>> cs(n);
    for(auto& [q,r] : cs) {
        read(q); cin >> r;
    }
    // check if overlap
    for(auto [q,r] : cs) {
        if(mnorm(q-p)<=(ll)r*r) {
            cout << "1\n";
            exit(0);
        }
    }
    // +'s and -'s from 0 to 1
    vector<pair<double,int>> ivs;

    auto canon = [&](double ang) {
        ang/=tau;
        while(ang<0) ang+=1;
        while(ang>1) ang-=1;
        return ang;
    };
    for(auto [q,r] : cs) {
        // find left and right bound
        double tanglen = sqrt(norm(q-p)-r*r);
        double ang = arg(q-p);
        double deltaA=-1;
        if(tanglen<=T) {
            // easier case: segments
            deltaA = asin(r/abs(q-p));
        } else {
            // harder case (circCirc intersection)
            if(abs(q-p)-r<T-1e-7) {
                deltaA=acos( (norm(p-q)+T*T - r*r)/(2*T*abs(p-q)) );
            } else continue;
        }
        if(deltaA<1e-10) continue; // doesn't contribute to answer
        ivs.push_back({canon(ang-deltaA),1});
        ivs.push_back({canon(ang+deltaA),-1});
    }
    if(ivs.size()==0) {
        cout << "0\n";
        exit(0);
    }
    sort(all(ivs));
    int overlap=0;
    for(auto [ang,sgn] : ivs) {
        overlap = max(0,overlap+sgn);
    }
    double ans=0, prevang = ivs.back().first-1.0;
    for(auto [ang,sgn] : ivs) {
        if(overlap) 
            ans+=ang-prevang;
        overlap+=sgn;
        prevang=ang;
    }
    cout << setprecision(9) << ans << '\n';
    
}