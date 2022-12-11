#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std; 
const int maxn=100100;
int n,q;
int a[maxn];
int bel[maxn];
int ppos[maxn],plmin[maxn];
int pre[maxn],preb[maxn],prebcnt[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void makeblock(){
	int T=sqrt(n);
	for(register int i=1;i<=n;++i)
		bel[i]=((i-1)/T)+1;
	for(register int i=1,x,pans;i<=n;++i){
		x=read();
		for(register int j=2;j*j<=x;++j)
			if(x%j==0){
				plmin[i]=max(plmin[i],ppos[j]);
				ppos[j]=i;
				while(x%j==0)x/=j;
			}
		if(x>1){
			plmin[i]=max(plmin[i],ppos[x]);
			ppos[x]=i;
		}
	}
	for(register int i=1,lp=0;i<=n;++i){
		lp=max(lp,plmin[i]);
		pre[i]=lp;
		if(bel[lp]!=bel[i]){
			preb[i]=lp;
			prebcnt[i]=1;
		}
		else{
			preb[i]=preb[lp];
			prebcnt[i]=prebcnt[lp]+1;
		}
	}
}
int main(){
	n=read();q=read();
	makeblock();
	for(register int i=1,l,r,ans;i<=q;++i){
		l=read();r=read();
		ans=0;
		while(bel[l]<bel[r]){
			ans+=prebcnt[r];
			r=preb[r];
		}
		while(r>=l){
			++ans;
			r=pre[r];
		}
		printf("%d\n",ans);
	}
	return 0;
}