#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5;
long long ans=0;
long long mask[N];
ll a[N],sum;
int lowbit[N],n;
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i],&mask[i]);
		sum+=a[i];
		for(int j=0;j<62;j++){
			if(1ll&(mask[i]>>j)){lowbit[i]=j;break;}
		}
		// cout << lowbit[i] << endl;
	}
	for(int i=61;~i;i--){
		ll cur=0;
		for(int j=1;j<=n;j++)if(lowbit[j]==i){
			cur+=a[j];
			// cout << i << " " << j << endl;
		}
		if(cur==0)continue;
		// if(cur!=0)cout << cur << "\\" << endl;
		// if(i==0)cout << cur << endl;
		if((cur>0)==(sum>0)){
			ans+=1ll<<i;
			for(int j=1;j<=n;j++)if(mask[j]&(1ll<<i)){
				a[j]=-a[j];
			}
		}
	}
	// for(int i=1;i<=n;i++)cout << (mask[i]&ans) << " ";puts("");
	cout << ans << endl;
}