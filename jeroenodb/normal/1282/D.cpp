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
int guess(string s) {
    cout << s << endl;
    int a; cin >> a;
    if(a==0) exit(0);
    return a;
}
int main() {
    int a = 300-guess(string(300,'a')), b = 300-guess(string(300,'b'));
    string res;
    int n = a+b;
    for(int i=0;i<n;++i) {
        if(!a) res.push_back('b'),b--;
        else if(!b) res.push_back('a'),a--;
        else {
            int ans = guess(res+'a'+string(b,'b'));
            if(ans==n-res.size()-1-b) res.push_back('a'),--a;
            else res.push_back('b'),--b;
        }
    }
    guess(res);
}