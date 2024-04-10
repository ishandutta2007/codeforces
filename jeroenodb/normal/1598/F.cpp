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
const int mxN = 20, oo = 1e9;
int ans = -oo, dp[1<<mxN];
void cmax(int& a, int b) {a=max(a,b);}
struct parstr {
    string s;
    vi bestbefore;
    int mn=oo, sum=0, mncnt=0;
    void read() {
        cin >> s;
        int n = s.size();
        for(int i=0;i<n;++i) {
            sum+=(s[i]=='('?1:-1);
            if(mn>sum)
                mncnt=0,mn=sum;
            if(sum==mn) 
                mncnt++;
        }
        bestbefore.resize(n+1,-oo);
    }
    int compute() {
        int n = s.size();
        mn=oo,sum=0,mncnt=0;
        int j = 0,res=-oo;
        for(int i=0;i<n;++i) {
            sum+=(s[i]=='('?1:-1);
            while(j<=n and j+sum<0) {
                cmax(res,bestbefore[j++]+mncnt);
            }
            if(mn>sum)
                mncnt=0,mn=sum;
            if(sum==mn) 
                mncnt++;
        }
        return res;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    vector<parstr> a(n);
    fill(dp,dp+(1<<n),-oo);
    for(auto& i : a) i.read();
    dp[0]=0;
    for(int i=0;i<1<<n;++i) if(dp[i]!=-oo) {
        ans = max(ans,dp[i]);
        int sum=0;
        for(int j=0;j<n;++j) if(1<<j & i) {
            sum+=a[j].sum;
        }
        for(int j=0;j<n;++j) if(!(1<<j & i)) {
            int to = i ^ (1<<j);
            if(sum+a[j].mn>0) cmax(dp[to],dp[i]);
            else if(sum+a[j].mn==0) {
                cmax(dp[to], dp[i]+a[j].mncnt);
            } else {
                cmax(a[j].bestbefore[sum], dp[i]);
            }
        }
    }
    for(auto& i : a) {
        ans = max(ans,i.compute());
    }
    cout << ans << '\n';
}