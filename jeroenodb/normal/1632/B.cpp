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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    // vi  v= {4, 6, 3, 2, 0, 8, 9, 1, 7, 5};
    // highest bit needs to be set 
    // 0,1,2,3,4,5,6,7 highest power of two
    while(t--) {
        int n; cin >> n;
        // unfinished grey code?
        int l = 1<<__lg(n-1);
        for(int i=l-1;i>=0;--i) cout << i << ' ';
        for(int i=l;i<n;++i) cout << i << ' ';
        cout << '\n';
        
    }
}