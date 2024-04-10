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
typedef pair<ll,ll> pl;
const int mxN = 1e5+1, oo = 1e9;
struct line {
    ll a,b; // a*x+b
    ll operator()(ll x) {return a*x+b;}
    ll intersect(const line& o) const {
        auto res =  abs(b-o.b)/abs(o.a-a);
        if(b-o.b<0) res*=-1;
        if(o.a-a<0) res*=-1;
        // calculate division rounded down
        return res;
    }  
};

vector<line> lines;
bool good(const line& left) {
    if(lines.size()<2) return true;
    auto &right = lines.end()[-2], &mid = lines.back();
    return right.intersect(mid)>mid.intersect(left);
}
ll mx(ll x) {
    int l=0,r=lines.size()-1;
    while(l<r) {
        int mid=(l+r)/2;
        if(lines[mid](x)>lines[mid+1](x)) {
            r=mid;
        } else l=mid+1;
    }
    return lines[l](x);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    lines.push_back({1,0});
    ll p=0,q=0;
    ll best=0;
    for(int i=0;i<n;++i) {
        int a; cin >> a;
        p+=a;
        q+=(ll)a*i;
        auto cur = q+mx(p);
        best = max(best,cur);
        line l = {-i,p*i-q};
        while(!good(l)) lines.pop_back();
        lines.push_back(l);
    }
    cout << best << '\n';
}