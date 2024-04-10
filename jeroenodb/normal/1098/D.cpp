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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // similar to coin queries
    // split into [1] [2] [3,4] [5,6,7,8] [9...16]
    int q; cin >> q;
    multiset<int> s[31] = {};
    ll sm[31] = {};
    int n=0;
    while(q--) {
        char op; int x;
        cin >> op >> x;
        int i=30;
        int add=op=='+'?x:-x;
        while(i>0 and 1<<(i-1)>=x) sm[i--]+=add;
        if(op=='+') s[i].insert(x),n++;
        else s[i].erase(s[i].find(x)),n--;
        int ans=0;
        bool good=!s[0].empty();
        for(i=1;i<31;++i)  {
            if(!s[i].empty() and sm[i]*2<*s[i].begin()) 
                ans+=good,good=true;
        }
        cout << max(0,n-1-ans) << '\n';
    }
}