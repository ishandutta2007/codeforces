#include<bits/stdc++.h>

#define LL long long
using namespace std;
const int N=2e3+10;
const LL mod=1e9+7;
int n,m,R;
struct node{
	int x,y;
	LL v;
}a[N];
LL C[N][N];
int abs(int x){
	if(x<0) x=-x;
	return x;
}
bitset<N> f[N],G;
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
memset(C,0,sizeof(C));
	C[0][0]=1;
	for(int i=1;i<=2000;++i){
		C[i][0]=1;
		for(int j=1;j<=i;++j){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
//	for(int i=0;i<=5;++i){
//		for(int j=0;j<=i;++j) cout<<C[i][j]<<" ";puts("");
//	}
	scanf("%d%d%d",&n,&m,&R);
	for(int i=1;i<=n;++i){
		scanf("%d%d%I64d",&a[i].x,&a[i].y,&a[i].v);
	}
	LL ans=0;
	for(int i=1;i<=n;++i){
		int k=0;
		for(int j=1;j<=n;++j){
			if(max(abs(a[i].x-a[j].x),abs(a[i].y-a[j].y))>R) {
				++k;
				f[i][j]=1;
			}
		}
		//cout<<"k "<<k<<endl;
		ans=(ans+(C[n][m]-C[k][m])%mod*(a[i].v*a[i].v%mod))%mod;
	}
	for(int i=1;i<=n;++i){
		int x,y,z;
		for(int j=i+1;j<=n;++j){
		//	if(i==j) continue;
			x=f[i].count();
			y=f[j].count();
			G=f[i]&f[j];
			z=G.count();
			//cout<<x<<" "<<y<<" "<<z<<endl;
			ans=(ans+(C[n][m]-C[x][m]-C[y][m]+C[z][m])%mod*(a[i].v*a[j].v%mod*(LL)2%mod))%mod;
		}
		//ans=(ans+(C[n][m]-C[k][m])%mod*(a[i].v*a[i].v%mod))%mod;
	}
	ans=(ans%mod+mod)%mod;
	cout<<ans<<endl;
	return 0; 
}