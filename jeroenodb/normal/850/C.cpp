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
map<unsigned, int> dp;
int solve(bitset<30> bs) {
    if(!bs.any()) return 0;
    if(dp.count(bs.to_ulong())) {
        return dp[bs.to_ulong()];
    }
    auto& c = dp[bs.to_ulong()];
    int k = 29;
    while(!bs[k]) k--;
    set<int> s;
    for(int i=1;i<=k;++i) {
        bitset<30> msk = (1<<(i)) - 1;
        auto nw = (((~msk)&bs)>>i) | (bs&msk);
        nw[0]=false;
        s.insert(solve(nw));
    }
    while(s.count(c)) c++;
    return c;
}
int main() {
    int n; cin >> n;
    map<int,set<int>> mp;
    for(int i=0;i<n;++i) {
        int a; cin >> a;
        for(int j=2;j*j<=a;++j) {
            if(a%j==0) {
              int tmp=0;
              while(a%j==0) {
                  a/=j,tmp++;
              }  
              mp[j].insert(tmp);
            }
        }
        if(a!=1) mp[a].insert(1);
    }
    // now calculate grundy numbers for each 
    int ans = 0;
    for(auto& [p,s] : mp) {
        // a move is: picking a k <= max in s
        // then everything >=k, gets -=k
        // runs in 2**29 in the worst case!
        // how many states get visited?
        // I think not too much
        bitset<30> bs;
        for(auto i : s) bs[i]=true;
        ans^=solve(bs);
    }
    cout << (ans==0?"Arpa":"Mojtaba") << '\n';
}