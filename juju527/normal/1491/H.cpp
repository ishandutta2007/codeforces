#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,maxb=325;
int n,q,B;
int f[maxn],F[maxn];
int b[maxn];
int L[maxb],R[maxb],laz[maxb];
bool tag[maxb];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int get_f(int x){return max(f[x]-laz[b[x]],1);}
inline int get_F(int x){return tag[b[x]]?max(f[x]-laz[b[x]],1):F[x];}
void rebuild(int id){
    if(tag[id])return ;
    int l=L[id],r=R[id];bool flag=1;
    for(int i=l;i<=r;i++)if(f[i]>=l){flag=0;break;}
    tag[id]=flag;if(flag)return ;
    for(int i=l;i<=r;i++)if(f[i]<l)F[i]=f[i];else F[i]=F[f[i]];
    return ;
}
void modify(int l,int r,int x){
    int bl=b[l],br=b[r];
    if(bl==br){
        for(int i=l;i<=r;i++)f[i]=max(f[i]-x,1);rebuild(bl);
        return ;
    }
    for(int i=bl+1;i<br;i++){
        if(tag[i])laz[i]=min(laz[i]+x,n);
        else{
            int lt=L[i],rt=R[i];
            for(int j=lt;j<=rt;j++)f[j]=max(f[j]-x,1);rebuild(i);
        }
    }
    int lt=L[br],rt=R[bl];
    for(int i=l;i<=rt;i++)f[i]=max(f[i]-x,1);rebuild(bl);
    for(int i=lt;i<=r;i++)f[i]=max(f[i]-x,1);rebuild(br);
    return ;
}
int lca(int x,int y){
    while(1){
        if(x<y)swap(x,y);
        if(x==y)return x;
        if(b[x]==b[y]&&get_F(x)==get_F(y)){
            while(x^y){
                if(x<y)swap(x,y);
                x=get_f(x);
            }
            return x;
        }
        if(b[x]==b[y])x=get_F(x),y=get_F(y);
        else x=get_F(x);
    }
}
int main(){
    n=read();q=read();B=sqrt(n);
    for(int i=2;i<=n;i++)f[i]=read();
    for(int i=2;i<=n;i++)b[i]=(i-1)/B+1;
    R[0]=1;for(int i=1;i<=b[n];i++)L[i]=R[i-1]+1,R[i]=min(i*B,n),rebuild(i);
    while(q--){
        int op,l,r,x;
        op=read();l=read();r=read();
        if(op==1)x=read(),modify(l,r,x);
        else printf("%d\n",lca(l,r));
    }
    return 0;
}