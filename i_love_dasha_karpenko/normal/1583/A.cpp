#pragma GCC Optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int MXSUM = 100*200+7;
const int N = 107;
int dp[N][MXSUM],composite[MXSUM];
pair<int,int> P[N][MXSUM];
int A[N];
void solve(){
    int n;
    cin>>n;
    int sum = 0;
    for(int i = 1;i<=n;++i){
        cin>>A[i];
        for(int w = sum;w>=0;--w){
            if (dp[i-1][w]>0 || w==0)
                if (dp[i][w+A[i]]<dp[i-1][w]+1){
                    dp[i][w+A[i]] = dp[i-1][w]+1;
                    P[i][w+A[i]] = {i-1,i};
                }
        }
        for(int w = sum;w>=0;--w){
            if (dp[i][w]<dp[i-1][w]){
                dp[i][w] = dp[i-1][w];
                P[i][w] = P[i-1][w];
            }
        }
        sum+=A[i];
    }
    int res = 0,num = 0,pos = n;
    for(int s = 2;s<=sum;++s){
        if (composite[s] && dp[n][s]>res){
            res = dp[n][s];
            num = s;
        }
    }
    cout<<res<<endl;
    while(num!=0){
        cout<<P[pos][num].second<<' ';
        pair<int,int> c = P[pos][num];
        pos = c.first;
        num-=A[c.second];
    }
    cout<<endl;
    for(int i = 1;i<=n;++i)
    for(int j = 0;j<=sum;++j)
        P[i][j] = {0,0},dp[i][j] = 0;
}
int check(int x){
    for(int i = 2;i*i<=x;++i){
        if (x%i==0)
            return 1;
    }
    return 0;
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for(int i = 2;i<MXSUM;++i)
        composite[i] = check(i);
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}