//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector
#define eb emplace_back
using namespace std;
const int maxn=5e5+5,maxb=3.2e4+5;
int n,q,mod;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
bool bj[maxb];
int len,pr[maxb];
void pre(int lim){
	for(int i=2;i<=lim;i++){
		if(!bj[i])pr[++len]=i;
		for(int j=1;1ll*pr[j]*i<=lim&&j<=len;j++){
			bj[i*pr[j]]=1;
			if(i%pr[j]==0)break;
		}
	}
	return ;
}
vec<pii> fac;
int res[maxn];
int p,lim,m;
int a[maxn],op[maxn][4];
int pw[30];
int sum[4*maxn],tag[4*maxn],cnt[4*maxn];
ll A,B;
int exgcd(int x,int y){
	if(!y){A=1,B=0;return x;}
	int g=exgcd(y,x%y);
	ll tmp=A;
	A=B;B=tmp-B*(x/y);
	return g;
}
int inv(int x){exgcd(x,m);return (A%m+m)%m;}
inline int add(int x){return (x>=m)?x-m:x;}
inline void pushup(int k){
	int ls=k<<1,rs=k<<1|1;
	sum[k]=(cnt[ls]>=lim)?0:1ll*sum[ls]*pw[cnt[ls]]%m;
	sum[k]=add(sum[k]+((cnt[rs]>=lim)?0:1ll*sum[rs]*pw[cnt[rs]]%m));
	return ;
}
void add_tag(int k,int v){sum[k]=1ll*sum[k]*v%m;tag[k]=1ll*tag[k]*v%m;return ;}
void add_cnt(int k,int c){cnt[k]+=c;return ;}
void pushdown(int k){
	if(tag[k]==1&&!cnt[k])return ;
	if(tag[k]>1)add_tag(k<<1,tag[k]),add_tag(k<<1|1,tag[k]),tag[k]=1;
	if(cnt[k])add_cnt(k<<1,cnt[k]),add_cnt(k<<1|1,cnt[k]),cnt[k]=0;
	return ;
}
void build(int k,int l,int r){
	sum[k]=cnt[k]=0,tag[k]=1;
	if(l==r){
		int aux=a[l];
		while(aux%p==0)aux/=p,cnt[k]++;
		sum[k]=aux%m;
		return ;
	}
	int mid=l+((r-l)>>1);
	build(k<<1,l,mid);build(k<<1|1,mid+1,r);
	pushup(k);
	return ;
}
void modify1(int k,int l,int r,int x,int y,int v,int c){
	if(l>=x&&r<=y){add_tag(k,v),add_cnt(k,c);return ;}
	int mid=l+((r-l)>>1);
	pushdown(k);
	if(x<=mid)modify1(k<<1,l,mid,x,y,v,c);
	if(y>mid)modify1(k<<1|1,mid+1,r,x,y,v,c);
	pushup(k);
	return ;
}
void modify2(int k,int l,int r,int x,int v,int c){
	if(l==r){sum[k]=1ll*sum[k]*v%m;cnt[k]-=c;return ;}
	int mid=l+((r-l)>>1);
	pushdown(k);
	if(x<=mid)modify2(k<<1,l,mid,x,v,c);
	else modify2(k<<1|1,mid+1,r,x,v,c);
	pushup(k);
	return ;
}
int query(int k,int l,int r,int x,int y){
	if(l>y||r<x||cnt[k]>=lim)return 0;
	if(l>=x&&r<=y)return (cnt[k]>=lim)?0:1ll*sum[k]*pw[cnt[k]]%m;
	int mid=l+((r-l)>>1);
	pushdown(k);pushup(k);
	return add(query(k<<1,l,mid,x,y)+query(k<<1|1,mid+1,r,x,y));
}
int main(){
    n=read();mod=read();
	for(int i=1;i<=n;i++)a[i]=read();
	pre(sqrt(mod));
	int cur=mod;
	for(int i=1;i<=len;i++){
		if(cur%pr[i])continue;
		int c=0;
		while(cur%pr[i]==0)cur/=pr[i],c++;
		fac.eb(pii(pr[i],c));
	}
	if(cur>1)fac.eb(pii(cur,1));
	q=read();
	for(int i=1;i<=q;i++){
		op[i][0]=read();
		if(op[i][0]==1)op[i][1]=read(),op[i][2]=read(),op[i][3]=read();
		else op[i][1]=read(),op[i][2]=read();
	}
	int prod=1;
	for(auto u:fac){
		p=u.fi;lim=u.se;
		pw[0]=1;for(int i=1;i<lim;i++)pw[i]=pw[i-1]*p;
		m=pw[lim-1]*p;
		build(1,1,n);
		exgcd(m,prod);prod*=m;
		int coef=((A%prod)+prod)%prod;
		for(int i=1;i<=q;i++){
			int opt=op[i][0],l,r,x,k,c=0;
			if(opt==1){
				l=op[i][1],r=op[i][2],x=op[i][3];
				while(x%p==0)x/=p,c++;
				modify1(1,1,n,l,r,x%m,c);
			}
			else if(opt==2){
				k=op[i][1],x=op[i][2];
				while(x%p==0)x/=p,c++;
				modify2(1,1,n,k,inv(x%m),c);
			}
			else{
				l=op[i][1],r=op[i][2];
				int w=query(1,1,n,l,r);
				res[i]=(1ll*(res[i]-w)*coef%prod*m%prod+prod)%prod+w;
				res[i]%=prod;
			}
		}
	}
	for(int i=1;i<=q;i++)if(op[i][0]==3)printf("%d\n",res[i]);
    return 0;
}