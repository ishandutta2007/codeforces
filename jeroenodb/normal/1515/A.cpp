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
    int t; cin >> t;
    while(t--) {
        int n,x; cin >> n >> x;
        int total=0;
        vi w(n); for(int& i: w) {
            cin >> i;
            total+=i;
        }
        sort(all(w));
        if(total==x) {
            cout << "NO\n";
            continue;
        }
        int pref=0;
        for(int i=0;i<n;++i) {
            if(pref+w[i]==x) {
                swap(w[i],w[i+1]);
            }
            pref+=w[i];
        }
        cout << "YES\n";
        cout << w << '\n';
    }
}