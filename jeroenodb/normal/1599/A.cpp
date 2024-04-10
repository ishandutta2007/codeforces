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
    int n; cin >> n;
    vi a(n); for(auto& i : a) cin >> i;
    string s; cin >> s;
    sort(all(a));
    int shifts=0;
    for(int i=0;i+1<n;++i) if(s[i]!=s[i+1]) 
        shifts++;
    int l=n-1-shifts,r=l;
    cout << a[l] << ' ' << s[0]  << '\n';
    char cl = s[0],cr = s[0];
    for(int i=1;i<n;++i) {
        if(s[i]!=s[i-1]) {
            cr^='L'^'R';
            cout << a[++r] << ' ' << cr << '\n';
        } else {
            cl^='L'^'R';
            cout << a[--l] << ' ' << cl << '\n';
        }
    }
}