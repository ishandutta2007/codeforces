//Problem E
#include<bits/stdc++.h>
using namespace std;
void rd(int &a){
    char ch=getchar();
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))a=(a<<1)+(a<<3)+(ch^48),ch=getchar();
}
void init();
const int N=1007,p=998244353;
#define ll long long
int add(int a,int b){a+=b;if(p<=a)a-=p;return a;}
int sub(int a,int b){a-=b;if(a<0)a+=p;return a;}
int mul(int a,int b){return (ll)a*b%p;}
int ksm(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=mul(ans,a);
        b>>=1,a=mul(a,a);
    }
    return ans;
}
int chu(int a,int b){return mul(a,ksm(b,p-2));}
int n,m,a[N][N],tot,r,c,d[N][N],S1,Sx,Sxx,Sy,Syy,Sd;
struct node{int v,i,j;}nod[N*N];
bool cmp(node a,node b){return a.v<b.v;}
int main(){init();
    for(int i=1,j=1;i<=tot;i=j){
        while(j<=tot&&nod[j].v==nod[i].v)++j;
        for(int id=i;id<j;id++){
            int x=nod[id].i,y=nod[id].j,xe=0;
            xe=mul(S1,add(mul(x,x),mul(y,y)));
            xe=sub(xe,mul(2,mul(x,Sx)));
            xe=add(xe,Sxx);
            xe=sub(xe,mul(2,mul(y,Sy)));
            xe=add(xe,Syy);
            xe=add(xe,Sd);
            d[x][y]=chu(xe,S1);
        }
        for(int id=i;id<j;id++){
            int x=nod[id].i,y=nod[id].j;
            S1=add(S1,1);
            Sx=add(Sx,x);
            Sy=add(Sy,y);
            Sxx=add(Sxx,mul(x,x));
            Syy=add(Syy,mul(y,y));
            Sd=add(Sd,d[x][y]);
        }//printf("%d %d\n",i,j);printf("%d %d %d %d %d %d\n",S1,Sx,Sy,Sxx,Syy,Sd);
    }
    printf("%d",d[r][c]);
    return 0;
}
void init(){
    rd(n);rd(m);
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)rd(a[i][j]),nod[++tot]=(node){a[i][j],i,j};
    rd(r);rd(c);
    sort(nod+1,nod+tot+1,cmp);
}