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

void solve() {
    int n; cin >> n;
    vi a(n); for(auto& i : a) cin >> i;
    
    for(int i=n-1;i>0;--i) {
        a.erase(unique(all(a)),a.end());
        int zeros = i+1-a.size();
        vi b(a.size()-1);
        for(int j=0;j+1<a.size();++j) {
            b[j] = a[j+1]-a[j];
        }
        sort(all(b));
        if(zeros) {
            b.insert(b.begin(),0);
        }
        swap(a,b);
    }
    cout << a[0] << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) solve();
}