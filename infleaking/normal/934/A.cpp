#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
ll a[100],b[100],n,m;
int main() {
	cin>>n>>m;
	ll ans=1LL<<62;
	for (int i=1;i<=n;i++)scanf("%I64d",&a[i]);
	for (int i=1;i<=m;i++)scanf("%I64d",&b[i]);
	for (int i=1;i<=n;i++){
		ll cc=-(1LL<<62);
		for (int j=1;j<=n;j++){
			if (i==j)continue;
			for (int k=1;k<=m;k++)cc=max(cc,a[j]*b[k]);
		}
		ans=min(ans,cc);
	}
	cout<<ans<<endl;
	
}