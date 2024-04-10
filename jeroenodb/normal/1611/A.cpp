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
        string s; cin >> s;
        if((s.back()-'0')%2==0) {
            cout << "0\n";
        } else if((s[0]-'0')%2==0) {
            cout << "1\n";
        } else {
            bool good=false;
            for(auto c : s) {
                c-='0';
                if(c%2==0) good=true;
            }
            if(good) cout << "2\n";
            else cout << "-1\n";
        }
    }
}