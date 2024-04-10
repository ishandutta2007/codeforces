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
void solve() {
    int a[4] = {};
    for(auto& i : a) cin >> i;
    string s; cin >> s;
    int n = s.size();
    int balance = count(all(s),'A');
    balance-=n-balance;
    if(balance!=a[0]-a[1]) {
        cout << "NO\n";
        return;
    }
    vector<bool> used(n),space(n+1);
    map<char,vector<pi>> rs;
    for(int i=0;i<n;) {
        int j=i;
        while(j<n-1 and s[j]!=s[j+1]) {
            ++j;
        }
        if(s[i]!=s[j]) {
            int use = 2+(s[i]=='B');
            rs[s[i]].push_back({(j-i+1)/2,i});
        }
        i=j+1;
    }
    
    for(auto [c,v] : rs) {
        sort(all(v));
        int use=2 + (c=='B');
        for(auto [len,pos] : v) if(a[use]>=len) {
            a[use]-=len;
            for(int k=0;k<2*len;k+=2) {
                used[k+pos]=used[k+pos+1]=true;
            }
        }
    }
    for(int i=0;i<n-1;++i) {
        if(!used[i] and !used[i+1] and s[i]!=s[i+1]) {
            if(s[i]=='A' and a[2]) {
                a[2]--;
                used[i]=used[i+1]=true;
            } else if(s[i]=='B' and a[3]) {
                used[i]=used[i+1]=true;
                a[3]--;
            }
        }
    }
    if(a[2]!=0 or a[3]!=0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";


}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        solve();
    }
}