#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
#define endl '\n'
#define all(var) var.begin(),var.end()
const int N = 20+7;
const int masksz = 1<<20;
pair<pair<int,int>,pair<int,int>> A[N];
pair<int,int> dp[masksz];
const int MAXN = 4e5+7;
const int SUM = MAXN*2;
int po[N],cnt[N][SUM];
const int INF = 1e9;
void solve(){
    po[0] = 1;
    for(int i = 1;i<N;++i)
        po[i] = po[i-1]<<1;
    int n;
    cin>>n;
    for(int i = 0;i<n;++i){
        string s;
        cin>>s;
        int mi = 0,sum = 0,clk = 0;
        for(char to:s){
            if (to=='(')
                ++sum;
            else --sum;
            if (mi>sum){
                mi = sum;
                clk = 0;
            }
            if (sum==mi)
                ++clk,cnt[i][MAXN+sum]++;;

        }
        A[i] = {{sum,mi},{s.length(),clk}};
    }

    int sz = (1<<n);
    int res = 0;
    for(int mask = 1;mask<masksz;++mask){
        dp[mask] = {-INF,-INF};
       for(int bit = 0;bit<n;++bit) {
           if (!(mask&po[bit]))
               continue;
           int submask = mask^po[bit];
           if (dp[submask]==pair<int,int>{-INF,-INF})
               continue;
           if (dp[submask].second+A[bit].first.second>=0){
               pair<int,int> eqv = dp[submask];
               eqv.second+=A[bit].first.first;
               eqv.first+=(A[bit].first.second==-dp[submask].second?A[bit].second.second:0);
               dp[mask] = max(dp[mask],eqv);
           }
           else{
               res = max(res,dp[submask].first+cnt[bit][MAXN-dp[submask].second]);
           }
       }
       res = max(res,dp[mask].first);
    }
    cout<<res<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
//    cin>>t;
    while(t--)
        solve();
}