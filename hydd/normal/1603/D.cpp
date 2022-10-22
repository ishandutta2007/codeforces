#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,k,phi[110000];
ll f[20][110000],pre[110000];
void init(int n){
    for (int i=1;i<=n;i++) phi[i]=i;
    for (int i=1;i<=n;i++)
    	for (int j=2;i*j<=n;j++)
    		phi[i*j]-=phi[i];
    for (int i=1;i<=n;i++) pre[i]=pre[i-1]+phi[i];
}
ll calc(int l,int r){
//	for (int i=l;i<=r;i++) res+=pre[r/i];
	ll res=0;
	for (int i=l,j;i<=r;i=j+1){
		j=r/(r/i);
		res+=pre[r/i]*max(min(j,r)-i+1,0);
	}
	return res;
}
void solve(int l,int r,int x,int y){
	if (l>r) return;
	int mid=(l+r)>>1;
	ll val=calc(x+1,mid); int pos;
	for (int i=x;i<=y&&i<=mid;i++){
		if (f[k-1][i]+val<f[k][mid]) f[k][mid]=f[k-1][i]+val,pos=i;
		val-=pre[mid/(i+1)];
	}
	solve(l,mid-1,x,pos); solve(mid+1,r,pos,y);
}
int main(){
	init(100000);
	memset(f,0x3f,sizeof(f)); f[0][0]=0;
	for (k=1;k<=17;k++) solve(1,100000,0,100000);
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&k);
		if (k>17){ printf("%d\n",n); continue;}
		printf("%lld\n",f[k][n]);
	}
	return 0;
}