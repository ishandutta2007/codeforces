#pragma GCC optimize("-O3")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define N 100050
#define M 320
#define Re register
using namespace std;
inline int Read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void write(int x){if (x<10) {putchar('0'+x); return;} write(x/10); putchar('0'+x%10);}
inline void writeln(int x){ if (x<0) putchar('-'),x*=-1; write(x); putchar('\n'); }
int n,m,E,ans;
int a[N],g[N],mx[M],fa[N],val[N],lz[M];
struct node{
    int num,F;
}d[M][N];
inline void reb(int x){
    int l=(x-1)*E+1,r=min(x*E,n);
    mx[x]=0;
    for(int i=l;i<=r;i++){
        if(a[i]>mx[x]) mx[x]=a[i];
        if(d[x][a[i]].F) fa[i]=d[x][a[i]].F;
        else{
            d[x][a[i]].F=fa[i]=i;
            val[i]=a[i];
        }
        d[x][a[i]].num++;
    }
}
//int find(int x){
//    return fa[x]^x?fa[x]=find(fa[x]):x;
//}
inline int find(int x){
    while (x^fa[x]) x=fa[x]=fa[fa[x]];  return x;
}
inline void Union(int x,int A,int B){
    if(d[x][B].F){
        d[x][B].num+=d[x][A].num;
        fa[d[x][A].F]=d[x][B].F;
        d[x][A].num=d[x][A].F=0;
    }
    else {
        d[x][B].num=d[x][A].num;
        d[x][B].F=d[x][A].F;
        val[d[x][B].F]=B;
        d[x][A].num=d[x][A].F=0;
    }
}
inline void upd(int x,int v){
    if((v<<1)<=mx[x]-lz[x]){
        for(int i=lz[x]+1;i<=lz[x]+v;i++)
            if(d[x][i].F) Union(x,i,i+v);
        lz[x]+=v;
    }
    else {
        for(int i=mx[x];i>lz[x]+v;i--)
            if(d[x][i].F) Union(x,i,i-v);
        mx[x]=min(mx[x],lz[x]+v);
    }
}
inline void push(int x){
    int l=(x-1)*E+1,r=min(x*E,n);
    for(Re int i=l;i<=r;i++){
        a[i]=val[find(i)];
        d[x][a[i]].F=d[x][a[i]].num=0;
        a[i]-=lz[x];
    }
    for(Re int i=l;i<=r;i++) fa[i]=0;
    lz[x]=0;
}
int main(){
    int op,l,r,x;
    n=Read();m=Read();
	E=ceil(sqrt(n));
    for(Re int i=1;i<=n;i++){
        a[i]=Read();
		g[i]=(i-1)/E+1;
    }
    for(Re int i=1;i<=g[n];i++) reb(i);
    while(m--){
        op=Read();l=Read();r=Read();x=Read();
        if(op^1){
            ans=0;
            if(g[l]^g[r]){
                for(Re int i=l;i<=g[l]*E;i++) if (val[find(i)]-lz[g[l]]==x) ans++;
                for(Re int i=(g[r]-1)*E+1;i<=r;i++) if (val[find(i)]-lz[g[r]]==x) ans++;
                for(Re int i=g[l]+1;i<g[r];i++) 
                    if(x+lz[i]<N) ans+=d[i][x+lz[i]].num;
            }
            else {
                for(Re int i=l;i<=r;i++) if (val[find(i)]-lz[g[l]]==x) ans++;
            }
            writeln(ans);
        }
        else{
            if(g[l]^g[r]){
                push(g[l]);push(g[r]);
                for(Re int i=l;i<=g[l]*E;i++) if(a[i]-x>0) a[i]-=x;
                for(Re int i=(g[r]-1)*E+1;i<=r;i++) if(a[i]-x>0) a[i]-=x;
                for(Re int i=g[l]+1;i<g[r];i++) upd(i,x);
                reb(g[l]);reb(g[r]);
            }
            else{
                push(g[l]);
                for(Re int i=l;i<=r;i++) if(a[i]-x>0) a[i]-=x;
                reb(g[l]);
            }
        }
    }
    return 0;
}