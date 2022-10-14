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
typedef complex<ll> pt;
#define X real()
#define Y imag()
const pt dir4[] = {{1,0},{0,1},{-1,0},{0,-1}};
const string wind = "RULD";
ll norm(pt p) {return abs(p.X)+abs(p.Y);}
pt get(char c) {
    return dir4[wind.find(c)];
}
void read(pt& p) {
    int a,b; cin >> a >> b;
    p = {a,b};
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pt at; read(at);
    pt to; read(to);
    pt v = to-at;
    int n; cin >> n;
    vector<pt> vs(n+1);
    for(int i=1;i<=n;++i) {
        char c; cin >> c;
        vs[i]=vs[i-1]+get(c);
    }
    ll lo=0, hi = 1e17;
    while(lo<hi) {
        ll mid = (lo+hi)/2;
        pt w = -v;
        ll times = mid/n;
        w+=vs.back()*times;
        w+=vs[mid%n];
        if(norm(w)<=mid) {
            hi=mid;
        } else lo=mid+1;
    }
    if(lo>=(ll)1e17) {
        cout << "-1\n";
    }else cout << lo << '\n';
}