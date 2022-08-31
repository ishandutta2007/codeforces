// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,S=1<<9,inf=0x7fffffff;
int n,m;
int cnt[S],c[N],mn[S][2];
int main(){
    c[0]=inf;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        int x,y,s=0;
        scanf("%d",&x);
        for(int j=1;j<=x;++j){
            scanf("%d",&y);
            s|=1<<y-1;
        }
        ++cnt[s];
    }
    for(int i=1;i<S;i<<=1){
        for(int j=0;j<S;++j){
            if(~j&i){
                cnt[j|i]+=cnt[j];
            }
        }
    }
    for(int i=1;i<=m;++i){
        int x,y,s=0;
        scanf("%d",&c[i]);
        scanf("%d",&x);
        for(int j=1;j<=x;++j){
            scanf("%d",&y);
            s|=1<<y-1;
        }
        x=i;
        if(c[x]<c[mn[s][0]]){
            swap(x,mn[s][0]);
        }
        if(c[x]<c[mn[s][1]]){
            swap(x,mn[s][1]);
        }
    }
    int mx=-1,cost=inf,a,b;
    for(int x=1;x<S;++x){
        for(int y=1;y<S;++y){
            if(x==y?mn[x][1]:mn[x][0]&&mn[y][0]){
                int t=c[mn[x][0]]+c[mn[y][x==y]];
                if(cnt[x|y]>mx||cnt[x|y]==mx&&t<cost){
                    mx=cnt[x|y];
                    cost=t;
                    a=mn[x][0];
                    b=mn[y][x==y];
                }
            }
        }
    }
    printf("%d %d\n",a,b);
    return 0;
}