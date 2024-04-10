#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[4][4];
ll C3(ll x){ return x*(x-1)*(x-2)/6;}
ll C2(ll x){ return x*(x-1)/2;}
int main(){
	scanf("%d",&n); int x,y;
	for (int i=1;i<=n;i++){
		scanf("%d%d",&x,&y);
		a[x&3][y&3]++;
	}
	ll ans=0;
	ans+=C3(a[0][0]); ans+=C3(a[0][2]); ans+=C3(a[2][0]); ans+=C3(a[2][2]);
	ans+=C2(a[0][0])*a[0][2]; ans+=C2(a[0][0])*a[2][0]; ans+=C2(a[0][0])*a[2][2];
	ans+=C2(a[0][2])*a[0][0]; ans+=C2(a[0][2])*a[2][0]; ans+=C2(a[0][2])*a[2][2];
	ans+=C2(a[2][0])*a[0][0]; ans+=C2(a[2][0])*a[0][2]; ans+=C2(a[2][0])*a[2][2];
	ans+=C2(a[2][2])*a[0][0]; ans+=C2(a[2][2])*a[0][2]; ans+=C2(a[2][2])*a[2][0];
	printf("%lld\n",ans);
	return 0;
}