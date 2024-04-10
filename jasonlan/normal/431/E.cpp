#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=201000;
int n,q,tnt;
bool op[maxn];
int pos[maxn],pxv[maxn];
int rk[maxn],cnt[maxn];
ll xv[maxn],xwat[maxn];
inline ll read(){
	ll res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res; 
}
void addc(int p,int x){
	while(p<=tnt)
		cnt[p]+=x,p+=p&-p;
}
void addw(int p,int x){
	while(p<=tnt)
		xwat[p]+=x,p+=p&-p;
}
ll queryc(int p){
	int res=0;
	while(p)res+=cnt[p],p-=p&-p;
	return res;
}
ll queryw(int p){
	ll res=0;
	while(p)res+=xwat[p],p-=p&-p;
	return res;
}
int main(){
	n=read();q=read();
	for(register int i=1;i<=n;++i){
		op[i]=1;
		rk[i]=xv[i]=read();
	}
	tnt=n;
	q+=n;
	for(register int i=n+1;i<=q;++i){
		if((op[i]=read()&1)){
			pos[i]=read();
			rk[++tnt]=xv[i]=read();
		}
		else xv[i]=read();
	}
	sort(rk+1,rk+1+tnt);
	tnt=unique(rk+1,rk+1+tnt)-rk-1;
	for(register int i=1;i<=q;++i)
		if(op[i])xv[i]=lower_bound(rk+1,rk+1+tnt,xv[i])-rk;
	for(register int i=1;i<=n;++i){
		addc(xv[i],1);
		addw(xv[i],rk[xv[i]]);
		pxv[i]=xv[i];
	}
	for(register int i=n+1;i<=q;++i){
		if(op[i]){
			addc(pxv[pos[i]],-1);
			addw(pxv[pos[i]],-rk[pxv[pos[i]]]);
			addc(xv[i],1);
			addw(xv[i],rk[xv[i]]);
			pxv[pos[i]]=xv[i];
		}
		else{
			int l=1,r=tnt,mid,lcnt;
			while(l<r){
				mid=(l+r+1)>>1;
				if(queryc(mid)*rk[mid]-queryw(mid)>xv[i])r=mid-1;
				else l=mid;
			}
			lcnt=queryc(l);
			l=1;r=tnt;
			while(l<r){
				mid=(l+r)>>1;
				if(queryc(mid)>=lcnt)r=mid;
				else l=mid+1;
			}
			double wans=(xv[i]-(1ll*lcnt*rk[l]-queryw(l)))*1.0/lcnt;
			printf("%.5lf\n",wans+rk[l]);
		}
	}
	return 0;
}