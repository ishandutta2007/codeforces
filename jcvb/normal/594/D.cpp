#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
typedef long long ll;
typedef double db;
const db pi=acos(-1);
void gn(int &x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
	if(c=='-')sg=-1,x=0;else x=c-'0';
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
	x*=sg;
}
void gn(ll &x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
	if(c=='-')sg=-1,x=0;else x=c-'0';
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
	x*=sg;
}
const int mo=1000000007;
const int inf=1061109567;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int bo[1000005]={0},pr[1000005],tot=0;
int lo[1111111];
int inv[1111111];
void sieve(int n){
	inv[1]=1;
	for (int i=2;i<=n;i++){
		if(!bo[i]){
			pr[++tot]=i;
			inv[i]=qp(i,mo-2);
			lo[i]=i;
		}
		for (int j=1;j<=tot && pr[j]*i<=n;j++){
			bo[i*pr[j]]=1;
			inv[i*pr[j]]=1ll*inv[i]*inv[pr[j]]%mo;
			lo[i*pr[j]]=pr[j];
			if(i%pr[j]==0){
				break;
			}
		}
	}
}
int n;

int a[222222];
int b[2222222];
int rig[222222];
struct quer{
	int l,r,id;
}qu[222222];
int cmp(const quer&a,const quer&b){
	return a.r<b.r;
}
int ans[222222];
int las[1222222]={0};
int bit[2222222];
int mul[2222222];

void bitupd(int x,int d){
	for(;x<=tot;x+=x&-x)bit[x]=1ll*bit[x]*d%mo;
}
int bitque(int x){
	int ans=1;
	for(;x;x-=x&-x)ans=1ll*ans*bit[x]%mo;
	return ans;
}

int main()
{
	sieve(1000000);
	gn(n);
	tot=0;
	for (int i=1;i<=n;i++){
		int x;
		gn(x);
		a[i]=x;
		while(x>1){
			int p=lo[x];
			while(x%p==0)x/=p;
			b[++tot]=p;
		}
		rig[i]=tot;
	}
	mul[0]=1;
	for (int i=1;i<=n;i++)mul[i]=1ll*mul[i-1]*a[i]%mo;
	int q;gn(q);
	for (int i=1;i<=q;i++){
		gn(qu[i].l);
		gn(qu[i].r);
		qu[i].id=i;
		ans[i]=1ll*mul[qu[i].r]*qp(mul[qu[i].l-1],mo-2)%mo;
		qu[i].l=rig[qu[i].l-1]+1;
		qu[i].r=rig[qu[i].r];
	}
	sort(qu+1,qu+1+q,cmp);
	int cur=1;
	for (int i=0;i<=tot;i++)bit[i]=1;
	for (int i=0;i<=tot;i++){
		if(i){
			if(las[b[i]]==0){
				bitupd(i,1ll*(b[i]-1)*inv[b[i]]%mo);
			}else{
				bitupd(las[b[i]],1ll*inv[b[i]-1]*b[i]%mo);
				bitupd(i,1ll*(b[i]-1)*inv[b[i]]%mo);
			}
			las[b[i]]=i;
		}
		while(cur!=q+1 && qu[cur].r==i){
			if(qu[cur].l>qu[cur].r){
				cur++;
				continue;
			}
			int ans=bitque(qu[cur].r);
			ans=1ll*ans*qp(bitque(qu[cur].l-1),mo-2)%mo;
			/*ans=1ll*mul[qu[cur].r]*ans%mo;
			ans=1ll*ans*qp(mul[qu[cur].l-1],mo-2)%mo;*/
			::ans[qu[cur].id]=1ll*::ans[qu[cur].id]*ans%mo;
			cur++;
		}
	}
	for (int i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}