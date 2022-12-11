#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,q;
const int maxn=101000;
int f[maxn],g[maxn],tag[maxn];
int cnt[maxn],L[maxn],bel[maxn],T;
void Restore(int x){
	for(int i=L[x];i<L[x+1];++i)
		f[i]=max(f[i]-tag[x],1);
	tag[x]=0;
    for(int i=L[x];i<L[x+1];++i){
        if(f[i]<L[x]||i==1)g[i]=f[i];
        else g[i]=g[f[i]];
    }
}
void modify(int l,int r,int x){
    if(bel[l]==bel[r]){
        for(int i=l;i<=r;++i)
            f[i]=max(f[i]-x,1);
        Restore(bel[l]);
    }
    else{
        for(int i=l;i<L[bel[l]+1];++i)
            f[i]=max(f[i]-x,1);
        Restore(bel[l]);
        for(int i=L[bel[r]];i<=r;++i)
            f[i]=max(f[i]-x,1);
        Restore(bel[r]);
        for(int i=bel[l]+1;i<bel[r];++i){
            ++cnt[i];
            tag[i]=min(tag[i]+x,n);
            if(cnt[i]<=T)Restore(i);
        }
    }
}
int query(int x,int y){
    while(1){
    	if(bel[x]<bel[y])swap(x,y);
    	if(bel[x]!=bel[y])x=max(1,g[x]-tag[bel[x]]);
    	else{
    		if(max(1,g[x]-tag[bel[x]])==max(1,g[y]-tag[bel[y]]))
    			break;
    		x=max(1,g[x]-tag[bel[x]]);
    		y=max(1,g[y]-tag[bel[y]]);
    	}
    }
    while(x!=y){
    	if(x<y)swap(x,y);
    	x=max(1,f[x]-tag[bel[x]]);
    }
    return x;
}
int main(){
    scanf("%d%d",&n,&q);
    f[1]=1;
    for(int i=2;i<=n;++i)
        scanf("%d",f+i);
    T=sqrt(n);
    L[1]=1;
    for(int j=1;L[j]<=n;++j){
        L[j+1]=min(L[j]+T,n+1);
        for(int k=L[j];k<L[j+1];++k)
            bel[k]=j;
        Restore(j);
    }
    for(int i=1,op,x,y,z;i<=q;++i){
        scanf("%d",&op);
        if(op==1){
            scanf("%d%d%d",&x,&y,&z);
            modify(x,y,z);
        }
        else{
            scanf("%d%d",&x,&y);
            printf("%d\n",query(x,y));
        }
    }
    return 0;
}