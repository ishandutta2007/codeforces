// Hydro submission #61473ae09169feba185ebfac@1632058080963
#include<algorithm>
#include<cstdio>
typedef long long ll;
const int maxn=1e5+5;
const int logn=2e1+5;
const ll inf=1152921502459363329;
int val[maxn];
ll qzh[maxn];
int mi[maxn][logn],lg[maxn];
void init(int n){
	for(int i=2;i<=n;i++)lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++)mi[i][0]=val[i];
	for(int j=1;(1<<j)<=n;j++)for(int i=1;i+(1<<j)-1<=n;i++)
		mi[i][j]=std::min(mi[i][j-1],mi[i+(1<<(j-1))][j-1]);
	return;
}
int ask(int l,int r){
	int k=lg[r-l+1];
	return std::min(mi[l][k],mi[r-(1<<k)+1][k]);
}
int n,c;
ll tot[maxn];
signed main(){
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++){
		scanf("%d",val+i);
		qzh[i]=qzh[i-1]+val[i];
	}
	init(n);
	for(int i=1;i<=n;i++)tot[i]=std::min(tot[i-1]+1ll*val[i],
		(i>=c?tot[i-c]+qzh[i]-qzh[i-c]-1ll*ask(i-c+1,i):inf));
	printf("%I64d",tot[n]);
	return 0;
}