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
    /*
    remove all 1's, they immediately make it bad
    dp[pos][last 10 chars] --> bruh, actually fast
    If x = prime
    always sum of x is bad. Avoid sum of x
    [.....]
      x total
    Define state as maximal string of the last characters that
    sum to <=x
    */
   unordered_map<string,int> dp;
   unordered_map<string,string> cache;
   dp[""]=0;
   string S; cin >> S;
   int x; cin >> x;
   auto sum = [&](const string& s) {
        int ans=0;
        for(auto c : s) ans+=c-'0';
        return ans;
   };
   for(auto c : S) {
        vector<pair<string,int>> old(all(dp));
        for(auto& [to,val] : dp) val++;
        for(auto& [from,val] : old) {
            
            from+=c;
            if(!cache.count(from)) {
                auto memofrom=from;
                auto isBad = [&](const string& t) {
                    bool good=true;
                    for(int l=0;good and l<(int)t.size();++l) {
                        for(int len=1;good and l+len<=(int)t.size();++len) {
                            int tmp = sum(t.substr(l,len));
                            if(tmp<x and x%tmp==0) good=false;
                        }
                    }
                    return !good;
                };
                while(sum(from)>x or isBad(from)) 
                    from.erase(from.begin());
                
                if(sum(from)==x) cache[memofrom]="-";
                else {
                    cache[memofrom]=from;
                    if(!dp.count(from)) dp[from]=oo;
                }
                from=memofrom;
            }
            string tmp = cache[from];
            if(tmp=="-") continue;
            auto& newdp = dp[tmp];
            newdp = min(newdp,val);
        }
   }
   int ans=oo;
   for(auto& [s,u] : dp) ans = min(ans,u);
   cout << ans << '\n';
}