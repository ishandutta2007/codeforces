#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
const int M=1e5+9;
int n,q;
int d[2][2][M];
ll f[M][23][2][2];
ll dis(int x,int y,int i,int o,int t){//i-1 0, i+1 1  0 top 1 right
    if(o==1){
        int fx=d[t][0][i];
        int fy=d[t][1][i];
        if(t==1){
            if(y==fy)return abs(x-fx)+1;
            else return abs(y-i)+abs(x-fx)+1;
        }
        else{
            if(x==fx)return abs(y-fy)+1;
            else return abs(x-i)+abs(y-fy)+1;
        }
    }
    else{
        int fx=d[t][0][i-1];
        int fy=d[t][1][i-1];
        if(t==1){
            fy++;
            if(y==fy)return abs(x-fx);
            else return abs(y-i)+abs(x-fx);
        }
        else{
            fx++;
            if(x==fx)return abs(y-fy);
            else return abs(x-i)+abs(y-fy);
        }
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<n;++i){
        scanf("%d%d%d%d",&d[0][0][i],&d[0][1][i],&d[1][0][i],&d[1][1][i]);
    }
    memset(f,0X3f,sizeof(f));
    for(int i=2;i<n;++i){
        for(int t2=0;t2<2;++t2){
            f[i][0][0][t2]=dis(d[0][0][i-1]+1,d[0][1][i-1],i,1,t2);
            f[i][0][1][t2]=dis(d[1][0][i-1],d[1][1][i-1]+1,i,1,t2);
        }
    }
    for(int j=1;j<19;++j){
        for(int i=2;i+(1<<j)-1<n;++i){
            for(int t1=0;t1<2;++t1){
                for(int t2=0;t2<2;++t2){
                    for(int t3=0;t3<2;++t3){
                        int x=i+(1<<j-1);
                        f[i][j][t1][t3]=min(f[i][j][t1][t3],f[i][j-1][t1][t2]+f[x][j-1][t2][t3]);
                    }
                }
            }
        }
    }
    scanf("%d",&q);
    for(int i=1;i<=q;++i){
        int bx,by,ex,ey;
        scanf("%d%d%d%d",&bx,&by,&ex,&ey);
        if(max(bx,by)>max(ex,ey))swap(bx,ex),swap(by,ey);
        int x=max(bx,by),y=max(ex,ey);
        if(max(bx,by)==max(ex,ey)){
            if(bx==ex){
                printf("%d\n",abs(by-ey));
            }
            else if(by==ey){
                printf("%d\n",abs(bx-ex));
            }
            else{
                printf("%d\n",abs(bx-x)+abs(ex-x)+abs(by-x)+abs(ey-x));
            }
        }
        else{
            
            ll t0=dis(bx,by,x,1,0),t1=dis(bx,by,x,1,1);
            x++;
            for(int j=19;j>=0;--j){
                if((y-x)>>j&1){
                    ll n0=t0;
                    ll n1=t1;
                    t0=min(n0+f[x][j][0][0],n1+f[x][j][1][0]);
                    t1=min(n0+f[x][j][0][1],n1+f[x][j][1][1]);
                    x+=1<<j;
                }
            }
            printf("%lld\n",min(t0+dis(ex,ey,y,0,0),t1+dis(ex,ey,y,0,1)));
        }
    }
    return 0;
}
/*
5
1 1 1 1
2 1 1 2
3 1 3 3
4 3 4 4
1
5 4 3 3


*/