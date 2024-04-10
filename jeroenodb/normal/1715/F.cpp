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
typedef complex<double> pt;
#define X real()
#define Y imag()

void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
void print(pt p) {
    cout << setprecision(15) << fixed << p.X << ' ' << p.Y << '\n';
}
double polygon(int n, int m, bool rot=false) {
    vector<pt> pts;
    pts.push_back({0,0});
    for(int i=1;i<=n;++i) {
        pts.push_back({i,m});
        if(i!=n) {
            pts.push_back({i,1e-15});
        }
    }
    pts.push_back({n,0});
    if(rot) for(auto& p : pts) p = {p.Y,p.X};
    cout << "? " << pts.size() << '\n';
    for(auto& p : pts) {
        print(p);
    }
    cout.flush();
    double res;
    cin >> res;
    double lo =0, hi = m-1;
    for(int rep=0;rep<100;++rep) {
        double mid = (lo+hi)*0.5;
        double average = 0.5*( (1-mid/m) + (1-(mid+1)/m) );
        if(average>res) {
            lo = mid;
        } else hi = mid;
    }
    return lo;
}
int main() {
    int n,m; cin >> n >> m;
    auto y = polygon(n,m);
    auto x = polygon(m,n,true);
    cout << "! "; print({x,y});
    cout.flush();

}