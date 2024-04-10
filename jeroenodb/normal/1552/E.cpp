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
int main() {
    int n,k; cin >> n >> k;
    vi a(n*k); for(auto& i : a) cin >> i,--i;

    vector<pi> ans(n,{-1,-1});
    int got=0;
    while(got<n) {
        vi prv(n,-1);
        int last=-1;
        for(int i=0;i<n*k;++i) {
            if(prv[a[i]]>last and ans[a[i]].first==-1) {
                ans[a[i]]= {prv[a[i]],i};
                last = i;
                got++;
            }
            prv[a[i]]=i;
        }
    }
    for(auto [aa,b]: ans) {
        cout << aa+1 << ' ' << b+1 << '\n';
    }
}