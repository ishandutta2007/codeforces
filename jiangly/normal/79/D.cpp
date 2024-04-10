#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k,l;
    scanf("%d%d%d",&n,&k,&l);
    vector<int>x0(k),x;
    for(auto &i:x0){
        scanf("%d",&i);
    }
    sort(x0.begin(),x0.end());
    k=unique(x0.begin(),x0.end())-x0.begin();
    x0.resize(k);
    for(int i=0;i<k;++i){
        if(i==0||x0[i]!=x0[i-1]+1){
            x.push_back(x0[i]-1);
        }
        if(i==k-1||x0[i]!=x0[i+1]-1){
            x.push_back(x0[i]);
        }
    }
    sort(x.begin(),x.end());
    vector<int>a(l);
    for(auto &i:a){
        scanf("%d",&i);
    }
    k=(int)x.size();
    vector<vector<int>>f(k);
    for(int i=0;i<k;++i){
        f[i].assign(n+1,-1);
        f[i][x[i]]=0;
        queue<int>q;
        q.push(x[i]);
        for(;q.size()>0;){
            int u=q.front();
            q.pop();
            for(auto j:a){
                if(u+j<=n&&f[i][u+j]==-1){
                    f[i][u+j]=f[i][u]+1;
                    q.push(u+j);
                }
                if(u-j>=0&&f[i][u-j]==-1){
                    f[i][u-j]=f[i][u]+1;
                    q.push(u-j);
                }
            }
        }
    }
    vector<int>dp(1<<k,-1);
    dp[0]=0;
    for(int s=0;s+1<(1<<k);++s){
        if(dp[s]==-1){
            continue;
        }
        int i;
        for(i=0;i<k;++i){
            if((s&(1<<i))==0){
                break;
            }
        }
        for(int j=i+1;j<k;++j){
            if((s&(1<<j))==0&&f[i][x[j]]!=-1&&(dp[s^(1<<i)^(1<<j)]==-1||dp[s^(1<<i)^(1<<j)]>dp[s]+f[i][x[j]])){
                dp[s^(1<<i)^(1<<j)]=dp[s]+f[i][x[j]];
            }
        }
    }
    printf("%d\n",dp[(1<<k)-1]);
	return 0;
}