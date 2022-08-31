// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
constexpr int MAX_N=1e6+5;
int n;
int a[MAX_N];
int dp[1<<21][2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    for(int i=n;i>=1;--i){
        if(dp[a[i]][0]==0){
            dp[a[i]][0]=i;
        }else if(dp[a[i]][1]==0){
            dp[a[i]][1]=i;
        }
    }
    for(int i=(1<<21)-1;i>=0;--i){
        for(int j=0;j<21;++j){
            if(i&(1<<j)){
                int t=i^(1<<j);
                int x=dp[i][0];
                if(x>dp[t][0]){
                    swap(x,dp[t][0]);
                }
                dp[t][1]=max(dp[t][1],dp[i][1]);
                if(x!=dp[t][0]){
                    dp[t][1]=max(dp[t][1],x);
                }
            }
        }
    }
    int ans=0;
    for(int k=20;k>=0;--k){
        bool ok=false;
        ans|=1<<k;
        for(int i=1;i<=n;++i){
            if(dp[ans&~a[i]][1]>i){
                ok=true;
            }
        }
        if(!ok){
            ans^=1<<k;
        }
    }
    cout<<ans<<endl;
    return 0;
}