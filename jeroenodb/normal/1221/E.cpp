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
        int a,b; string s;
        cin >> a >> b >> s;
        s.push_back('X');
        int n = s.size();
        int must=0, flip=0,bad=0;
        bool choose=false;
        auto check = [&](int len) {
            if(len<b) return;
            if(len<a) bad++;
            else if(len<2*b) flip++;
            else {
                if(len<=a+2*b-2) {
                    if(len>=a*2) {
                        choose=true;
                        must++;
                    } else must++;
                } else {
                    // makes at least one b move possible
                    if(len<2*a or len-a>4*b-2) bad++;
                    else {
                        // len>=2*a
                        // can make one
                        int cnt=0;
                        if(len-a <b-1 + 2*b) cnt++,flip++;
                        if(len>=3*a) cnt++;
                        if(cnt==0) bad++;
                        else must++;
                        if(cnt==2) choose=true;
                    }
                }
                
            }
            
        };
        int len=0;
        for(int i=0;i<n;++i) {
            if(s[i]=='X') {
                check(len);
                len=0;
            } else len++;
        }
        auto good = [&]() {
            if(bad or must>1) return false;
            if(choose) return true;
            return (must+flip)%2==1;
        };
        if(good()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}