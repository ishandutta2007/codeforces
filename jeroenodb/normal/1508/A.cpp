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
void f(string a, string b, string& best) {
    if(!best.empty()) return;
    int n = a.size();
    int o1 = count(all(a),'1'), o2 = count(all(b),'1');
    char c = '1';
    if(o1>=n/2 and o2>=n/2) {
        c = '0';
    } else if((o1>n/2 and o2<n/2) or (o1<n/2 and o2>n/2) ) {
        return;
    }
    string ans;
    int i,j;
    for(i=0,j=0;i<n and j<n;) {
        if(a[i]==b[j]) { 
            ans+=a[i];
            ++i,++j;
        } else {
            ans+=c;
            if(a[i]==c) i++;
            if(b[j]==c) j++;
        }
    }
    if(i<n) 
        ans+=a.substr(i);
    if(j<n) 
        ans+=b.substr(j);
    best = ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s[3];
        cin >> s[0] >> s[1] >> s[2];
        string ans;
        f(s[0],s[1],ans); 
        f(s[1],s[2],ans); 
        f(s[0], s[2],ans);
        assert((int)ans.size()<=3*n);
        cout << ans << '\n';

    }
}