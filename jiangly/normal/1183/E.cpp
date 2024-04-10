// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long long k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<vector<int>>next(n);
    for(int i=n-1;i>=0;--i){
        if(i==n-1){
            next[i].assign(26,-1);
        }else{
            next[i]=next[i+1];
        }
        next[i][s[i]-'a']=i;
    }
    vector<vector<long long>>dp(n+1);
    for(int i=0;i<=n;++i){
        dp[i].resize(n+1);
    }
    dp[0][0]=1;
    for(int i=0;i<n;++i){
        for(int j=0;j<=i;++j){
            for(int k=0;k<26;++k){
                if(next[i][k]!=-1){
                    dp[next[i][k]+1][j+1]+=dp[i][j];
                }
            }
        }
    }
    vector<long long>sum(n+1);
    for(int i=0;i<=n;++i){
        for(int j=0;j<=i;++j){
            sum[j]+=dp[i][j];
        }
    }
    long long ans=0;
    for(int i=n;i>=0&&k>0;--i){
        long long delta=min(k,sum[i]);
        ans+=delta*(n-i);
        k-=delta;
    }
    if(k>0){
        puts("-1");
    }else{
        cout<<ans<<endl;
    }
    return 0;
}