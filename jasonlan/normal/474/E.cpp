#include<iostream>
#include<cstdio>
#include<algorithm>
#define mid ((l+r)>>1)
using namespace std;
const int maxn=101000;
typedef long long ll;
int n,d,q,ans;
ll a[maxn],rk[maxn];
int rt,ver,son[2][maxn<<1],mxi[maxn<<1],mpos[maxn<<1];
int pos,f[maxn],pre[maxn];
inline ll read(){
	ll res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1==-'-'?-res:res;
}
void update(int p){
	if(mxi[son[0][p]]>mxi[son[1][p]]){
		mxi[p]=mxi[son[0][p]];
		mpos[p]=mpos[son[0][p]];
	}
	else{
		mxi[p]=mxi[son[1][p]];
		mpos[p]=mpos[son[1][p]];
	}
}
void build(int &p,int l,int r){
	p=++ver;
	if(l==r){
		mxi[p]=-0x3f3f3f3f;return;
	}
	build(son[0][p],l,mid);
	build(son[1][p],mid+1,r);
}
void modify(int p,int xp,int l,int r){
	if(l==r){
		mxi[p]=f[pos];mpos[p]=pos;return;
	}
	if(xp<=mid)modify(son[0][p],xp,l,mid);
	else modify(son[1][p],xp,mid+1,r);
	update(p);
}
void query(int p,int lr,int rr,int l,int r){
	if(lr<=l&&r<=rr){
		if(mxi[p]+1>f[pos]){
			f[pos]=mxi[p]+1;
			pre[pos]=mpos[p];
		}
		return;
	}
	if(lr>r||l>rr)return;
	query(son[0][p],lr,rr,l,mid);
	query(son[1][p],lr,rr,mid+1,r);
}
int main(){
	n=read();d=read();
	for(int i=1;i<=n;++i)
		a[i]=rk[i]=read();
	sort(rk+1,rk+1+n);
	q=unique(rk+1,rk+1+n)-rk-1;
	build(rt,1,q);
	for(pos=n;pos;--pos){
		f[pos]=1;pre[pos]=0;
		int t;
		t=upper_bound(rk+1,rk+1+q,a[pos]-d)-rk-1;
		if(t>=1)query(rt,1,t,1,q);
		t=lower_bound(rk+1,rk+1+q,a[pos]+d)-rk;
		if(t<=q)query(rt,t,q,1,q);
		if(f[ans]<f[pos])ans=pos;
		t=lower_bound(rk+1,rk+1+q,a[pos])-rk;
		modify(rt,t,1,q);
	}
	printf("%d\n",f[ans]);
	while(ans){
		printf("%d ",ans);
		ans=pre[ans];
	}
	return 0;
}