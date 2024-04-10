#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=205;
int id[N][N],n,m,t,mo;
int fa[N*N],rn[N*N],t1;
int gf(int x){return fa[x]==x?x:fa[x]=gf(fa[x]);}
int ty[N][N];
ll c[N][N],cnt,ans;
int fail;
void merge(int x,int y){
	if (gf(x)==gf(y))fail=1;
	fa[gf(x)]=gf(y);
}
ll power(ll a,ll b=mo-2){
	ll ans=1;
	while (b){
		if (b&1)ans=ans*a%mo;
		a=a*a%mo;
		b>>=1;
	}return ans;
}
int ths[N],used[N];
void solve(int n){
	if (n>201)return;
	for (int i=1;i<=n;i++){
		int sum=0;
		for (int j=1;j<=n;j++)c[i][j]%=mo,sum+=c[i][j];
		c[i][i]=(c[i][i]-sum+mo)%mo;
	}n--;
	for (int i=1;i<=n;i++){
		int k=0;
		for (int j=1;j<=n;j++){
			if (!used[j]&&c[j][i]){
				k=j;
				break;
			}
		}
		if (!k)return;
		ths[i]=k;
		used[k]=1;
		ll z=power(c[k][i]);
		for (int j=1;j<=n;j++){
			if (!used[j]&&c[j][i]){
				ll p=mo-z*c[j][i]%mo;
				for (int u=1;u<=n;u++)
					c[j][u]=(c[j][u]+p*c[k][u])%mo;
			}
		}
	}
	ll prd=1;
	for (int i=1;i<=n;i++)prd=prd*c[ths[i]][i]*-1%mo;
	for (int i=1;i<=n;i++)
		for (int j=1;j<i;j++)
			if (ths[i]<ths[j])prd*=-1;
	ans=(ans+prd+mo)%mo;
}
int main(){
	cin>>n>>m>>mo;
	for (int i=1;i<=n+1;i++)
		for (int j=1;j<=m+1;j++)
			id[i][j]=++t,fa[t]=t;
	for (int i=1;i<=n;i++){
		scanf("\n");
		for (int j=1;j<=m;j++){
			ty[i][j]=getchar();
			if (ty[i][j]=='\\')
				merge(id[i][j],id[i+1][j+1]);
			if (ty[i][j]=='/')
				merge(id[i+1][j],id[i][j+1]);
		}
	}
	for (int i=1;i<=n+1;i++)
	for (int j=1;j<=m+1;j++){
		if ((i+j)&1)continue;
		if (fa[id[i][j]]==id[i][j])rn[id[i][j]]=++t1;
		t1=min(t1,202);
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++){
		if (ty[i][j]=='*');else continue;
		if ((i+j)&1){
			c[rn[gf(id[i+1][j])]][rn[gf(id[i][j+1])]]++;
			c[rn[gf(id[i][j+1])]][rn[gf(id[i+1][j])]]++;
		}
		else {
			c[rn[gf(id[i+1][j+1])]][rn[gf(id[i][j])]]++;
			c[rn[gf(id[i][j])]][rn[gf(id[i+1][j+1])]]++;			
		}
	}
	solve(t1);
	memset(c,0,sizeof c);
	memset(ths,0,sizeof ths);
	memset(used,0,sizeof used);
	t1=0;	
	for (int i=1;i<=n+1;i++)
	for (int j=1;j<=m+1;j++){
		if ((i+j)&1);else continue;
		if (fa[id[i][j]]==id[i][j])rn[id[i][j]]=++t1;
		t1=min(t1,201);
	}
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++){
		if (ty[i][j]=='*');else continue;
		if ((i+j)&1){
			c[rn[gf(id[i+1][j+1])]][rn[gf(id[i][j])]]++;
			c[rn[gf(id[i][j])]][rn[gf(id[i+1][j+1])]]++;
		}
		else {
			c[rn[gf(id[i+1][j])]][rn[gf(id[i][j+1])]]++;
			c[rn[gf(id[i][j+1])]][rn[gf(id[i+1][j])]]++;	
		}
	}
	solve(t1);
	cout<<ans*(!fail)<<endl;
}