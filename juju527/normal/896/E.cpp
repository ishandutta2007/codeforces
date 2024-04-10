#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5,maxm=5e5+5,maxw=5e5+5,maxb=1e3+5;
int n,m,W,B,S;
int mx,laz;
int a[maxn];
int rt[maxw];
int c[maxb];
int f[maxb];
short siz[maxb];
int op[maxm][4];
int res[maxm];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int L,R;
inline void merge(int &u,int v){
    if(!u){u=v;return ;}
    f[v]=u;siz[u]+=siz[v];
    return ;
}
inline void clear(){
//    for(int i=L;i<=R;i++)f[id[i]]=c[id[i]]=siz[id[i]]=0;
    for(int i=1;i<=W+laz;i++)rt[i]=0;
    return ;
}
short id[maxn];
inline void rebuild(int l,int r,int x){
    for(int i=L;i<=R;i++)a[id[i]]=c[find(id[i])]-laz;
    for(int i=L;i<=R;i++)rt[a[id[i]]+laz]=c[id[i]]=0,f[id[i]]=id[i],siz[id[i]]=1;
    for(int i=l;i<=r;i++)if(a[id[i]]>x)a[id[i]]-=x;
    mx=laz=0;
    for(int i=L;i<=R;i++){
        int y=id[i];
        if(!rt[a[y]])c[y]=a[y];
        merge(rt[a[y]],y);
        mx=max(mx,a[y]);
    }
    return ;
}
int main(){
    n=read();m=read();B=sqrt(n);S=(n-1)/B+1;
//    cout<<B<<" "<<S<<endl;
    for(int i=1;i<=n;i++)a[i]=read(),W=max(W,a[i]);
    for(int i=1;i<=m;i++)op[i][0]=read(),op[i][1]=read(),op[i][2]=read(),op[i][3]=read();
    for(int b=1;b<=S;b++){
        L=b*B-B+1,R=min(b*B,n);
        mx=laz=0;
        for(int i=L;i<=R;i++)id[i]=i-L+1,f[id[i]]=id[i],siz[id[i]]=1,c[id[i]]=a[i];
        rebuild(1,0,0);
        for(int i=1;i<=m;i++){
            int opt=op[i][0],l=op[i][1],r=op[i][2],x=op[i][3];
            if(l>R||r<L||mx<x||x==0)continue;
            if(opt==1){
                if(mx==x)continue;
                if(l>=L||r<=R)rebuild(max(l,L),min(r,R),x);
                else{
                    if(mx<=2*x){
                        for(int v=x+1;v<=mx;v++){
                            if(!rt[v+laz])continue;
                            if(!rt[v-x+laz])c[rt[v+laz]]=v-x+laz;
                            merge(rt[v-x+laz],rt[v+laz]),rt[v+laz]=0;
                        }
                        mx-=x;
                        for(int v=x;v>=mx;v--)if(siz[rt[v+laz]]){mx=v;break;}
                    }
                    else{
                        for(int v=1;v<=x;v++){
                            if(!rt[v+laz])continue;
                            if(!rt[v+x+laz])c[rt[v+laz]]=v+x+laz;
                            merge(rt[v+x+laz],rt[v+laz]),rt[v+laz]=0;
                        }
                        laz+=x,mx-=x;
                    }
                }
            }
            else{
                int sum=0;
                if(l>=L||r<=R){
                    for(int j=max(l,L);j<=min(r,R);j++){
                        int co=c[find(id[j])]-laz;
                        if(co==x)sum++;
                    }
                }
                else if(x+laz<maxw)sum=siz[rt[x+laz]];
                res[i]+=sum;
            }
//            cout<<i<<"|";
//            for(int j=1;j<=100;j++)if(siz[rt[j]])cout<<"("<<j<<","<<siz[rt[j]]<<") ";cout<<endl;
//            cout<<mx<<" "<<laz<<endl;
        }
        clear();
    }
    for(int i=1;i<=m;i++)if(op[i][0]==2)printf("%d\n",res[i]);
    return 0;
}