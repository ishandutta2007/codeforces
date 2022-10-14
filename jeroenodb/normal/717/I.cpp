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
typedef valarray<ll> pt;
typedef valarray<long double> ptF;
void read(pt& p) {
    p.resize(3);
    for(auto& i : p ) cin >> i;
}
pt outer(const pt& a, const pt& b) {
    pt res = {a[1]*b[2]-a[2]*b[1], a[2]*b[0]-a[0]*b[2], a[0]*b[1]-a[1]*b[0]};
    return res;
}
ptF outer(const ptF& a, const ptF& b) {
    ptF res = {a[1]*b[2]-a[2]*b[1], a[2]*b[0]-a[0]*b[2], a[0]*b[1]-a[1]*b[0]};
    return res;
}
ll in(const pt& a, const pt& b) {
    return (a*b).sum();
}
struct plane {
    pt normal;
    ll d;
    plane(pt a, pt b, pt c) {
        // outer product
        normal = outer(b-a,c-a);
        d = in(normal,a);
    }
    bool side(pt p) {
        return in(p,normal) < d;
    }
};
pair<vector<pt>,plane> readpoly() {
    int n; cin >> n;
    vector<pt> pts(n);
    for(auto& i : pts) read(i);
    auto myplane = plane(pts[0],pts[1],pts[2]);
    return {pts,myplane};
}

ptF toptF(pt p) {
    ptF res;
    res.resize(3);
    for(int i=0;i<3;++i) res[i]=p[i];
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    auto [a,pa] = readpoly();
    auto [b,pb] = readpoly();
    auto dir = outer(toptF(pa.normal), toptF(pb.normal));
    auto magnitude = sqrtl((dir*dir).sum());;
    if(magnitude<=1e-10L) {
        cout << "NO\n";
        exit(0);
    }
    dir/=magnitude;
    auto getIS = [&dir](const vector<pt>& poly, plane b) {
        auto prev = poly.back();
        vector<long double> res;
        for(auto i : poly) {
            if(b.side(i) != b.side(prev)) {
                // lies somewhere on the line, congruencies!
                auto mix =  (b.d-in(b.normal,prev))/(long double)in(b.normal,i-prev);
                ptF p = mix*toptF(i)+ (1.L-mix)*toptF(prev);
                res.push_back((p*dir).sum());
            }
            prev= i;
        }
        sort(all(res));
        return res;
    };
    auto as = getIS(a,pb), bs = getIS(b,pa);
    int winding =0, inside=0, sgn=1;
    // now simple check
    auto it = bs.begin();
    for(auto i : as) {
        while(it!=bs.end() and *it < i) {
            inside^=1;
            ++it;
        }
        winding+=inside*sgn;
        sgn*=-1;
    }
    cout << (winding==0?"NO\n":"YES\n");


}