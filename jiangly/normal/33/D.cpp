#include<bits/stdc++.h>
const int MAXN=1000,MAXM=1000;
int n,m,k;
std::bitset<MAXM+5>a[MAXN+5];
int Kx[MAXN+5],Ky[MAXN+5],r[MAXM+5],Cx[MAXM+5],Cy[MAXM+5];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&Kx[i],&Ky[i]);
	for(int i=1;i<=m;++i)
		scanf("%d%d%d",&r[i],&Cx[i],&Cy[i]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			a[i][j]=1ll*(Kx[i]-Cx[j])*(Kx[i]-Cx[j])+1ll*(Ky[i]-Cy[j])*(Ky[i]-Cy[j])<1ll*r[j]*r[j];
	for(int i=1;i<=k;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%d\n",a[u].count()+a[v].count()-(a[u]&a[v]).count()*2);
	}
	return 0;
}