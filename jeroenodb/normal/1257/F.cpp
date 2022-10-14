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

const int LG = 30, HV = LG/2;
typedef map<vector<char>,int> mymap;
mymap makemap(vi a,int sgn = 1) {
    mymap ans;
    int n = a.size();
    for(int i=0;i<1<<HV;++i) {
        vector<char> res(n-1);
        for(int j=1;j<n;++j) {
            res[j-1] = sgn*( bitset<HV>(i^a[j]).count() - bitset<HV>(i^a[j-1]).count());
        }
        if(!ans.count(res)) ans[res]=i;
    }
    return ans;
}
int main() {
    int n; cin >> n;
    vi a(n),b(n);
    for(int i=0;i<n;++i) {
        cin >> b[i];
        a[i] = b[i]>>HV;
        b[i]&=(1<<HV)-1;
    }
    auto ma = makemap(a), mb = makemap(b,-1);
    for(auto [ar,i] : ma) {
        if(mb.count(ar)) {
            cout << ((i<<HV)|mb[ar]) << '\n';
            exit(0);
        }
    }
    cout << "-1\n";
}