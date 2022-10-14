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
    vector<int> c(n);
    for(auto& i : c) cin >> i;
    // pref = 
    stack<pair<ll,ll>> s;
    s.push({0,0});
    ll ans=0;
    bool flip=false;
    for(auto i : c) {
        if(flip) {
            while(i and !s.empty()) {
                auto& [height,num] = s.top();
                if(height<i) {
                    i-=height;
                    ans+=height+num;
                    s.pop();
                } else {
                    if(height==i) ans+=num;
                    height-=i;
                    ans+=i;
                    i=0;
                }
            }
            if(!s.empty() and s.top().first==0) s.top().second++;
            else s.push({0,i==0});
           
        } else {
            auto& p = s.top();
            p.first+=i;
        }
        flip=!flip;
    }
    cout << ans << '\n';
}