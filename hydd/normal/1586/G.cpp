#include<bits/stdc++.h>
using namespace std;
const int Mod=1e9+7;
int n,m,l[210000],r[210000],p[210000];
bool c[210000]; int v[210000],tree[410000];
void add(int x,int y){
	for (;x;x-=x&-x) tree[x]=(tree[x]+y)%Mod;
}
int query(int x){
	int res=0;
	for (;x<=(n<<1);x+=x&-x) res=(res+tree[x])%Mod;
	return res;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&l[i],&r[i]);
		p[i]=i;
	}
	sort(p+1,p+n+1,[&](int x,int y)->bool{ return r[x]<r[y];});
	scanf("%d",&m); int u;
	for (int i=1;i<=m;i++){
		scanf("%d",&u);
		c[u]=true;
	}
	for (int i=1;i<=n;i++){
		u=p[i];
		v[u]=(query(l[u])+1)%Mod; add(l[u],v[u]);
	}
	int lst=1,ans=0;
	for (int i=n;i>=1;i--){
		u=p[i];
		add(l[u],Mod-v[u]);
		if (c[u]&&l[u]>=lst){
			ans=(ans+query(lst)+1)%Mod;
			lst=l[u];
		}
	}
	printf("%d\n",ans);
	return 0;
}