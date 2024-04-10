#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
const int mn=2e5+10;
int p[mn],bit[mn],ans[mn];
vector<int>ad[mn];
vector<pii>qu[mn];
void up(int a,int b){for(;a<mn;a+=a&-a)bit[a]+=b;}
int que(int a){int b=0;for(;a;a-=a&-a)b+=bit[a];return b;}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        p[x]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            int a=min(p[i],p[j]),b=max(p[i],p[j]);
            ad[a].push_back(b);
        }
    }
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        qu[a].push_back({b,i});
    }
    for(int i=n;i;i--){
        for(int x:ad[i])up(x,1);
        for(pii p:qu[i])ans[p.second]=que(p.first);
    }
    for(int i=0;i<m;i++)printf("%d\n",ans[i]);
}