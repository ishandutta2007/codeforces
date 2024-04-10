#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
#define b(x) (1<<((x)-1))
int i,j,k,n,m,t,f[300500],a[300500],b[300500],sb,l,r,md,ans,tmp;
ll jc[1005000],inv[1005000];
bool vis[300500];
ll c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}
void add(int x,int y){for(;x<=200000;x+=(-x&x)){f[x]+=y;}}
vector<int> v;
int main() {
	jc[0]=inv[0]=1;
	for(i=1;i<=1000000;i++){jc[i]=jc[i-1]*i%M;}
	inv[1000000]=490058372;
	for(i=999999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;i++){
			scanf("%d%d",&b[i],&a[i]);
		}
		sb=0;
		for(i=m;i>=1;i--){
			l=0;ans=0;r=(1<<18);
			for(j=18;j>=1;j--){
				r>>=1;if(l+r-ans-f[l+r]<a[i]){l+=r;ans+=f[l];}
			}
			ans=l+1;
			if(!vis[ans+1]){sb++;}
			add(ans,1);
			v.push_back(ans);
			vis[ans]=1;
		}
		printf("%lld\n",c(n+n-1-sb,n));
		for(auto i:v){
			vis[i]=0;add(i,-1);
		}
		v.clear();
	}
}