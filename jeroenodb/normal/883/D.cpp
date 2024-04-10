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

vi p,until;
int n;
void cmax(int& a, int b) {a=max(a,b);}
int maxAsterisk(int t) {
    vi dp(p.size()+1,-oo);
    dp[0]=-1;
    for(int i =1;i<=p.size();++i) {
        int at = p[i-1];
        if(until[max(at-t,0)]<=dp[i-1]) {
            cmax(dp[i],max(dp[i-1],at));
        }
        if(until[at]<=dp[i-1]) {
            cmax(dp[i],max(dp[i-1],at+t));
        }
        if(i>=2 and at-p[i-2]<=t) {
            if(until[max(at-t,0)]<=dp[i-2]) {
                cmax(dp[i],max(p[i-2]+t,dp[i-2]));
            }
        }
    }
    return dp.back();
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> n >> s;
    until.resize(n+1,-1);
    for(int i=0;i<n;++i) {
        if(s[i]=='P') p.push_back(i);
        if(s[i]=='*') {
            until[i+1]=i;
        } else until[i+1]=until[i];
    }

    if(p.size()==1) {
        // check sides
        pi best = {-oo,-oo};
        int cnt=0,last=oo;
        for(int i=p[0]-1;i>=0;--i) {
            if(s[i]=='*') cnt++,last=i;
        }
        best = max(best,{cnt,last-p[0]});
        cnt=0,last=-oo;
        for(int i=p[0]+1;i<n;++i) {
            if(s[i]=='*') cnt++,last=i;
        }
        best = max(best,{cnt,p[0]-last});
        cout << best.first << ' ' << -best.second << '\n';
        exit(0);
    }
    int lo=1,hi=n;
    while(lo<hi) {
        auto mid = (lo+hi)/2;
        int rightmost = maxAsterisk(mid);
        if(rightmost>=until[n]) {
            hi = mid;
        } else lo = mid+1;
    }
    cout << count(all(s),'*') << ' ' << lo << '\n';
}