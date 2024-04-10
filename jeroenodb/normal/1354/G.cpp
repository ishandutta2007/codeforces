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
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<class I> I rnd(I l,I r){return std::uniform_int_distribution<I>(l,r)(rng);}
int comp(vi a, vi b) {
    cout << "? " << a.size() << ' ' << b.size() << '\n';
    cout << a << '\n' << b << endl;
    string res; cin >> res;
    if(res=="FIRST") return 1;
    if(res=="SECOND") return -1;
    if(res=="EQUAL") return 0;
    exit(0);
};
int solve() {
    int n,k; cin >> n >> k;
    int mx=1;
    for(int i=0;i<20;++i) {
        int maybe = rnd(1,n);
        if(maybe!=mx and comp({mx},{maybe})<0) {
            mx = maybe;
        }
    }
    if(mx!=1 and comp({mx},{1})!=0) return 1;
    mx=1;
    int l=-1,r=n;
    for(int j=2;j<=n;j*=2) {
        vi a(j/2), b(j/2);
        iota(all(a),1), iota(all(b),j/2 + 1);
        if(comp(a,b)!=0) {
            l=j/2+1, r = j;
            break;
        }
        l=j+1;
    }
    vi a(l);
    iota(all(a),1);
    while(l<r) {
        int mid = (l+r)/2;
        vi b; for(int j=l;j<=mid;++j) b.push_back(j);
        if(comp(vi(a.begin(),a.begin()+b.size()), b)==0) {
            l=mid+1;
        } else r = mid;
    }
    return l;
}
int main() {
    int t; cin >> t; while(t--) {
        auto res = solve();
        cout << "! " << res << endl;
    }
}