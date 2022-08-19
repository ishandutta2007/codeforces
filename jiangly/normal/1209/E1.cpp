#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> a(n,vector<int>(m));
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin>>a[i][j];
            }
        }
        vector<int> mx(m);
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                mx[i]=max(mx[i],a[j][i]);
            }
        }
        vector<int> p(m);
        for(int i=0;i<m;++i){
            p[i]=i;
        }
        sort(p.begin(),p.end(),[&](int a,int b){
            return mx[a]>mx[b];
        });
        vector<vector<int>> dp(2,vector<int>(1<<n));
        for(int i=0;i<min(n,m);++i){
            swap(dp[0],dp[1]);
            dp[1].assign(1<<n,0);
            for(int mask=0;mask<(1<<n);++mask){
                int tmp=0;
                for(int x=0;x<n;++x){
                    int res=0;
                    for(int j=0;j<n;++j){
                        if(mask>>j&1){
                            res+=a[(x+j)%n][p[i]];
                        }
                    }
                    tmp=max(tmp,res);
                }
                int other=((1<<n)-1)^mask;
                for(int s=other;s>0;s=(s-1)&other){
                    dp[1][s|mask]=max(dp[1][s|mask],dp[0][s]+tmp);
                }
                dp[1][mask]=max(dp[1][mask],tmp);
            }
        }
        cout<<dp[1][(1<<n)-1]<<endl;
    }
    return 0;
}