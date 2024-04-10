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
        int n; cin >> n;
        vi s(n); for(int& i: s) cin >> i;
        ll ans = 0;

        vi people(n);
        for(int i=0;i<n;++i) {

            // simulate process
            // must be faster
            int delta = max(0,s[i]-1-people[i]);
            ans+=delta;
            people[i]+=delta;
            int olds = s[i];
            if(s[i]+i>=n) {
                s[i] = max(1,n-1-i);
            }
            people[i] = max(0,people[i]-(olds-s[i]));
            // could be faster with delta array, and slowly building the array
            for(int j=i+2;j<=min(n-1,s[i]+i);++j) {
                people[j]++;
                people[i]--;
            }
            if(i<n-1) people[i+1]+=people[i];
        }
        cout << ans << endl;
    }
}