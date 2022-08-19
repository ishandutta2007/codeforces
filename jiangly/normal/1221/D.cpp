#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;++i){
            cin>>a[i]>>b[i];
        }
        LL dp[2][3]={};
        dp[0][0]=0;
        dp[0][1]=b[0];
        dp[0][2]=2*b[0];
        int cur=0;
        for(int i=1;i<n;++i){
            cur^=1;
            for(int j=0;j<=2;++j){
                dp[cur][j]=1e18;
                for(int k=0;k<=2;++k){
                    if(a[i]+j!=a[i-1]+k){
                        dp[cur][j]=min(dp[cur][j],dp[cur^1][k]+j*b[i]);
                    }
                }
            }
        }
        cout<<min(dp[cur][0],min(dp[cur][1],dp[cur][2]))<<endl;
    }
    return 0;
}