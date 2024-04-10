#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int mn = 2e5+10;
const ll mod = 1e9+7;

int a[mn],ma[mn*5];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i],ma[a[i]]=a[i];
	sort(a,a+n);
	for(int i=mn*5-2;i>=0;i--)if(!ma[i])ma[i]=ma[i+1];
	int ans=0;
	ll num = 0;
	for(int i=n-1;i>=0;i--){
		//cerr<<a[i]<<" "<<ans<<endl;
		if(a[i]<=ans)break;
		int cur=INT_MAX;
		for(int j=2;1;j++){
			int nxt=a[i]/j+1;
			if(cur==nxt||cur<=ans)break;
			//cerr<<ma[nxt]<<" "<<a[i]<<endl;
			ans=max(ans,a[i]%ma[nxt]);
			cur=nxt;
		}
		//cerr<<cur<<endl;
		if(cur<=ans)continue;
		for(int j=0;a[j]<cur;j++)ans=max(ans,a[i]%a[j]);
	}
	printf("%d\n",ans);
}