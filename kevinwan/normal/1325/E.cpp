#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=1e6+10;
const ll mod=1e9+7;
int a[mn];
vector<int>g[mn];
set<pii>s;
int dis[mn],bac[mn];
int main(){
    int n,m;
    scanf("%d",&n);
    int ans=0x3f3f3f3f;
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
        for(int j=2;j*j<=a[i];j++)while(a[i]%(j*j)==0)a[i]/=j*j;
        if(a[i]==1){
            printf("1");
            return 0;
        }
        for(int j=2;j*j<=a[i];j++){
            if(a[i]%j==0){
                int k=a[i]/j;
                if(s.count({j,k})){
                    ans=min(ans,2);
                }
                g[j].push_back(k);
                g[k].push_back(j);
                a[i]=1;
            }
        }
        if(a[i]>1){
            if(s.count({1,a[i]})){
                ans=min(ans,2);
            }
            g[1].push_back(a[i]);
            g[a[i]].push_back(1);
        }
    }
    if(ans==2)printf("%d",ans);
    for(int i=1;i<=1000;i++){
        if(!g[i].size())continue;
        memset(dis,0x3f,sizeof(dis));
        dis[i]=0;
        queue<int>q;
        q.push(i);
        while(q.size()){
            int x=q.front();
            q.pop();
            for(int y:g[x]){
                if(dis[y]==0x3f3f3f3f){
                    dis[y]=dis[x]+1;
                    bac[y]=x;
                    q.push(y);
                }
                else if(bac[x]!=y)ans=min(ans,dis[x]+dis[y]+1);
            }
        }
    }
    if(ans>1e9)printf("-1");
    else printf("%d",ans);
}