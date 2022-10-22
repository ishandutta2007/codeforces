#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5,maxw=1e7+5,W=1e7;
int a[maxn];
int pre[maxw];
int f[maxn][20];
int g[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
bool bj[maxw];
int len;
int p[maxw],minp[maxw];
void Pre(){
    for(int i=2;i<=W;i++){
        if(!bj[i])p[++len]=i,minp[i]=i;
        for(int j=1;1ll*i*p[j]<=W&&j<=len;j++){
            bj[i*p[j]]=1;
            minp[i*p[j]]=p[j];
            if(i%p[j]==0)break;
        }
    }
    return ;
}
int lg[maxn];
int get(int l,int r){
    int len=lg[r-l+1];
    return max(f[l][len],f[r-(1<<len)+1][len]);
}
int main(){
    int T;
    T=read();
    Pre();
    for(int i=1;i<=W;i++)pre[i]=-1;
    while(T--){
        int n,k;
        n=read();k=read();
        for(int i=1;i<=n;i++){
            int x,pr=0,c=0;
            x=read();
            a[i]=1;
            while(x>1){
                if(pr&&minp[x]>pr){
                    if(c&1)a[i]=a[i]*pr;
                    c=0;
                }
                pr=minp[x];
                x/=minp[x];
                c++;
            }
            if(pr&&(c&1))a[i]=a[i]*pr;
            f[i][0]=pre[a[i]]+1;
            pre[a[i]]=i;
        }
        f[0][0]=0;
        for(int j=1;j<=19;j++)
            for(int i=0;i<=n-(1<<j)+1;i++)
                f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
        lg[0]=-1;
        for(int i=1;i<=n+1;i++)lg[i]=lg[i>>1]+1;
        g[0]=0;
        for(int i=1;i<=n;i++){
            int l=-1,r=i-1,mid;
            while(l+1<r){
                mid=l+((r-l)>>1);
                if(get(mid+1,i)>mid+1)l=mid;
                else r=mid;
            }
            g[i]=g[r]+1;
        }
        printf("%d\n",g[n]);
        for(int i=1;i<=n;i++)pre[a[i]]=-1;
        for(int j=1;j<=19;j++)for(int i=0;i<=n-(1<<j)+1;i++)f[i][j]=0;
    }
    return 0;
}