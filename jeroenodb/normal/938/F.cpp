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
const int mxN = 1<<12, oo = 1e9;

int main() {
    string res;
    string s; cin >> s;
    int n = s.size();
    int k = __lg(n);
    bitset<mxN> dp = {};
    dp[0]=true;
    int len=n;
    for(int i=0;i<k;++i) len-=1<<i;
    for(int i=1;i<=len;++i) {
        bitset<mxN> ndp = dp;
        char minc='z';
        for(int j=ndp._Find_first();j<1<<k;j=ndp._Find_next(j)) {
            for(int o=0;o<k;++o) {
                ndp[j|1<<o]=true;
            }
            minc = min(minc,s[i+j-1]);
        }
        res.push_back(minc);
        for(int j=ndp._Find_first();j<1<<k;j=ndp._Find_next(j)) {
            if(s[i+j-1]!=minc) ndp[j]=false;
        }
        dp=ndp;
    }
    cout << res << '\n';
}