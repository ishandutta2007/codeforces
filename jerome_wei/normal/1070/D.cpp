#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll a[N];
int n;
ll k;
ll sum=0;
ll pst=0;
ll ans=0;
int main()
{
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		//cout<<pst<<' '<<endl;
		//cout<<a[i]<<'i'<<sum+a[i]<<endl;
		sum+=a[i];
		ll NN=pst/k;if(NN*k<pst)NN++;
		ll K=sum/k;
		//cout<<sum<<' '<<endl;
		//cout<<NN<<' '<<K<<endl;
		ll rmv=max(NN,K);
		//cout<<rmv<<endl;
		ans+=rmv;
		sum-=rmv*k;
		sum=max(sum,0ll);
		pst=sum;
	}
	if(pst)ans+=(pst-1)/k+1;
	printf("%lld\n",ans);
}