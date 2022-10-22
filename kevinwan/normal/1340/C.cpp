#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=1e4+10;
const int mg=1e3+10;
const ll mod=1e9+7;
int d[mn];
int dis[mn*mg];
bool vis[mn*mg];
int main() {
    int n,m,r,k;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)scanf("%d",d+i);
    sort(d,d+m);
    scanf("%d%d",&k,&r);
    memset(dis,0x3f,sizeof(dis));
    deque<int>pq;
    pq.push_back(0);
    dis[0]=0;
    while(pq.size()){
        int x=pq[0];
        pq.pop_front();
        if(vis[x])continue;
        vis[x]=1;
        int a=x/mg,b=x%mg;
        if(a!=m-1) {
            int nxt =b+ d[a+ 1] - d[a];
            if (nxt <= k) {
                if (nxt != k){
                    int y=(a+1)*mg+nxt;
                    if(dis[x]<dis[y]){
                        dis[y]=dis[x];
                        pq.push_front(y);
                    }
                }
                else{
                    int y=(a+1)*mg;
                    if(dis[x]+1<dis[y]){
                        dis[y]=dis[x]+1;
                        pq.push_back(y);
                    }
                }
            }
        }
        if(a){
            int nxt =b+ d[a] - d[a-1];
            if (nxt <= k) {
                if (nxt != k){
                    int y=(a-1)*mg+nxt;
                    if(dis[x]<dis[y]){
                        dis[y]=dis[x];
                        pq.push_front(y);
                    }
                }
                else{
                    int y=(a-1)*mg;
                    if(dis[x]+1<dis[y]){
                        dis[y]=dis[x]+1;
                        pq.push_back(y);
                    }
                }
            }
        }
    }
    int ans=0x3f3f3f3f;
    ans=min((ll)ans,1LL*dis[(m-1)*mg]*(r+k)-r);
    for(int i=1;i<k;i++)ans=min((ll)ans,1LL*dis[(m-1)*mg+i]*(r+k)+i);
    if(ans<0x3f3f3f3f)printf("%d",ans);
    else printf("-1");
}