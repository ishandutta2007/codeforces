#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
struct bian{
	int next,point;
}b[600010];
int n,m,len,p[300010],f[300010],q,d[300010],w[300010],g[300010],fa[300010],pd[300010],a[300010],where[300010];
int findfather(int k){
	if (f[k]==k) return k;
	f[k]=findfather(f[k]); return f[k];
}
void ade(int k1,int k2){
	len++; b[len].point=k2; b[len].next=p[k1]; p[k1]=len;
}
void add(int k1,int k2){
	ade(k1,k2); ade(k2,k1);
}
void dfs(int k1,int k2){
	pd[k1]=1; 
    for (int i=p[k1];i;i=b[i].next){
        int j=b[i].point;
        if (j!=k2){
            dfs(j,k1); if (fa[j]+1>fa[k1]){g[k1]=fa[k1]; fa[k1]=fa[j]+1; where[k1]=j;} else if (fa[j]+1>g[k1]) g[k1]=fa[j]+1;
        }
    }
}
void dfs2(int k1,int k2){
	if (where[k2]==k1) a[k1]=max(g[k2],a[k2])+1; else a[k1]=max(fa[k2],a[k2])+1;
	if (k2==0) a[k1]=0;
    for (int i=p[k1];i;i=b[i].next){
        int j=b[i].point;
        if (j!=k2) dfs2(j,k1);
    }
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<=n;i++){w[i]=1; d[i]=1; f[i]=i;} len=0;
	for (int i=1;i<=m;i++){
		int k1,k2; scanf("%d%d",&k1,&k2); add(k1,k2);
		k1=findfather(k1); k2=findfather(k2);
		if (k1!=k2) f[k2]=k1;
	}
	memset(pd,0x00,sizeof pd);
	memset(fa,0x00,sizeof fa);
	memset(a,0x00,sizeof a);
	memset(g,0x00,sizeof g); a[0]=-1; f[0]=-1; g[0]=-1;
	for (int i=1;i<=n;i++) if (pd[i]==0){dfs(i,0); dfs2(i,0);}
	for (int i=1;i<=n;i++) d[i]=max(fa[i],a[i])+1;
	for (int i=1;i<=n;i++){int k=findfather(i); w[k]=max(w[k],fa[i]+g[i]+1); d[k]=min(d[k],max(fa[i],a[i])+1);} 
	for (;q;q--){
		int k1,k2; scanf("%d",&k1);
		if (k1==1){
			scanf("%d",&k1); k1=findfather(k1); printf("%d\n",w[k1]-1);
		} else{
			scanf("%d%d",&k1,&k2);
			k1=findfather(k1); k2=findfather(k2);
			if (k1!=k2){
				w[k1]=max(max(w[k1],w[k2]),d[k1]+d[k2]); int pdd; if (d[k1]==d[k2]) pdd=1; else pdd=0;  d[k1]=max(d[k1],d[k2])+pdd; f[k2]=k1;
			}
		}
	}
	return 0;
}