#include<bits/stdc++.h>
using namespace std;
const int inv2=500000004;
const int mod=1e9+7;
const int M=6e5+9;
int n,q;
int a[M],b[M],c[M],op[M],cnt[M],id[M],pw[M],iw[M];
int lv[M<<2],rv[M<<2],val[M<<2],siz[M<<2];
void pushup(int num){
	lv[num]=(lv[num<<1]+1ll*lv[num<<1|1]*pw[siz[num<<1]]%mod)%mod;
	rv[num]=(rv[num<<1]+1ll*rv[num<<1|1]*iw[siz[num<<1]]%mod)%mod; 
	val[num]=(val[num<<1]+val[num<<1|1]+1ll*lv[num<<1]*rv[num<<1|1]%mod*iw[siz[num<<1]]%mod)%mod;
	siz[num]=siz[num<<1]+siz[num<<1|1];
}
void update(int num,int l,int r,int x,int v){
	if(l==r){
		if(v){
			siz[num]=1;
			lv[num]=1ll*v;
			rv[num]=1ll*v*iw[1]%mod;
			val[num]=0;
		}
		else {
			siz[num]=lv[num]=rv[num]=val[num]=0;
		}
		return;
		
	}
	int mid=l+r>>1;
	if(x<=mid)update(num<<1,l,mid,x,v);
	else update(num<<1|1,mid+1,r,x,v);
	pushup(num);
}
int main(){
	pw[0]=iw[0]=1;
	for(int i=1;i<M;++i){
		pw[i]=2ll*pw[i-1]%mod;
		iw[i]=1ll*inv2*iw[i-1]%mod;
	}
	int m=0;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),c[++m]=a[i];
	scanf("%d",&q);
	for(int i=1;i<=q;++i){
		scanf("%d%d",&op[i],&b[i]);
		c[++m]=b[i];
	} 
	sort(c+1,c+m+1);
	for(int i=1;i<=n;++i){
		int x=lower_bound(c+1,c+m+1,a[i])-c;
		x+=cnt[x]++;
		update(1,1,m,x,a[i]);
		id[i]=x;
	}
	printf("%d\n",val[1]);
	for(int i=1;i<=q;++i){
		update(1,1,m,id[op[i]],0);
		int x=lower_bound(c+1,c+m+1,b[i])-c;
		x+=cnt[x]++;
		update(1,1,m,x,b[i]);
		id[op[i]]=x;
		printf("%d\n",val[1]);
	}
	return 0;
}