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
const int mxN = 1e5+1;
long double phi = 1/2.0L;
const ll oo = 1e18;
int qused;
ll amount;
ll secret;
ll dp[106][106];
void init() {
    for(int i=0;i<=105;++i) {
        for(int j=0;j<=105;++j) {
            dp[i][j] = -1;
        }
    }
}
ll getsize(int left, int chances) {
    if(left<=0) {
        return 0LL;
    }
    if(chances==0) {
        return getsize(left-1,chances+1);
    }
    if(dp[left][chances]!=-1) {
        return dp[left][chances];
    }
    return dp[left][chances] = min(oo,getsize(left-1,chances+1)+getsize(left-1,chances-1)+1);
}
bool test(ll a) {
    qused++;
    #ifndef LOCAL
    cout << "? " << a << endl;
    string ans; cin >> ans;
    if(ans=="Fired!") {
        exit(0);
    } 
    if(ans[0]=='L') {
    #else
    if(a<=secret) {
    #endif
        amount+=a;
        return true;
    } else {
        amount-=a;
        return false;
    }

}
void solve() {
    ll l=0,r= 1e14;
    qused=0;
    amount = 1;
    for(int i=0;i<=46;++i) {
        if(!test(1LL<<i)) {
            if(i==0) {
                cout << "! 0" << endl;
                return;
            }
            r = 1LL<<i;
            break;
        }
        l=  1LL<<i;
    }
    int c = amount/l;
    while(l<r) {
        int left = 105-qused;
        while(getsize(left-1,c)>=r-l+1) {
            left--;
        }
        if(c==0) {
            test(l);
            c++;
        } else {
            ll mid = min((l+r+1)/2,l + max(1LL,getsize(left-1,c-1)));
            while(amount<mid) 
                test(l); // extra tests, few needed.
            if(test(mid)) {
                ++c;
                l = mid;
            } else {
                --c;
                r = mid-1;
            }
        }
    }
    cout << "! " << l << endl;
}
int main() {
    init();
    int t=40; 
    #ifndef LOCAL
    cin >> t;
    #endif

    while(t--) {
        // secret = ll(1e14)-rand();
        solve();
        debug(qused);
        if(qused>105) {
            cerr << "Oops\n";
        }
        secret*=5;
    }
}