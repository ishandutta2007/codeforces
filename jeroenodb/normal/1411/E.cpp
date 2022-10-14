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
    int n; ll t;
    cin >> n >> t;
    string s; cin >> s;
    for(auto& i : s) i-='a';
    t-=1<<s.back();
    s.pop_back();
    t+=1<<s.back();
    s.pop_back();
    for(auto c : s) t+=1<<c;
    sort(s.rbegin(),s.rend());
    for(auto c : s) {
        int w = 2<<c;
        if(t>=w) t-=w;
    }
    cout << (t==0?"YES\n":"NO\n");
}