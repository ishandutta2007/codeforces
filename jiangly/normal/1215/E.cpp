#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const LL INF=1e18;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin>>n;
    vector<int> pos[20];
    for(int i=0;i<n;++i){
        int a;
        cin>>a;
        pos[a-1].push_back(i);
    }
    LL p[20][20]={};
    for(int x=0;x<20;++x){
        for(int y=0;y<20;++y){
            if(x==y){
                continue;
            }
            int a=0,b=0;
            while(a<pos[x].size()&&b<pos[y].size()){
                if(pos[x][a]<pos[y][b]){
                    p[x][y]+=b;
                    ++a;
                }else{
                    ++b;
                }
            }
            p[x][y]+=1ll*(pos[x].size()-a)*b;
        }
    }
    LL cost[20][1<<20]={};
    LL dp[1<<20]={};
    for(int x=0;x<20;++x){
        for(int y=0;y<20;++y){
            if(x!=y){
                cost[x][1<<y]=p[y][x];
            }
        }
        for(int mask=1;mask<(1<<20);++mask){
            if(mask>>x&1){
                continue;
            }
            int s=mask&-mask;
            cost[x][mask]=cost[x][s]+cost[x][mask^s];
        }
    }
    for(int mask=1;mask<(1<<20);++mask){
        dp[mask]=INF;
        for(int x=0;x<20;++x){
            if(mask>>x&1){
                dp[mask]=min(dp[mask],dp[mask^(1<<x)]+cost[x][mask^(1<<x)]);
            }
        }
    }
    cout<<dp[(1<<20)-1]<<endl;
    return 0;
}