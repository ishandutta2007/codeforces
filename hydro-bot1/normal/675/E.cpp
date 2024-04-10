// Hydro submission #621d77b0cdb5d839880c891e@1646098352527
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],st[22][N],cnt[N];
long long ans,f[N];
int ask(int l,int r){
	int p=cnt[r-l+1];
	int x=st[p][l],y=st[p][r-(1<<p)+1];
	return a[x]>a[y]?x:y;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)st[0][i]=i;
	for(int i=1;i<=20;i++)for(int j=1;j+(1<<(i-1))-1<=n;j++){
		int x=st[i-1][j],y=st[i-1][j+(1<<(i-1))];
		st[i][j]=a[x]>a[y]?x:y;
	}
	for(int i=2;i<=n;i++)cnt[i]=cnt[i>>1]+1;
	for(int i=n-1;i>=1;i--){
		int k=ask(i+1,a[i]);
		f[i]=f[k]+n-i-(a[i]-k);
		ans+=f[i];
	}
	printf("%lld",ans);
}