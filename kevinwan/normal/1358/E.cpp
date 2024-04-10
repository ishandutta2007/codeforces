#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
 
const int mn = 1e6+10;
const ll mod = 1e9+7;

ll a[mn];
ll fa[mn];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n;
	ll x;
	cin>>n;
	int m=(n+1)/2;
	for(int i=0;i<m;i++)cin>>a[i];
	cin>>x;
	if(x>=0){
		ll sum=0;
		for(int i=0;i<m;i++)sum+=a[i];
		sum+=(n/2)*x;
		if(sum<=0)printf("-1\n");
		else printf("%d\n",n);
		return 0;
	}
	for(int i=m-1;i>=0;i--)a[i]+=a[i+1];
	for(int i=0;i<=m;i++){
		int as=n+1-i;
		ll fail=(a[i]-x-1)/(-x)+m-i;
		//cerr<<as<<endl;
		fail=min(max(fail,(ll)m),(ll)as);
		//cerr<<fail<<endl;
		fa[fail]++;
		fa[as]--;
	}
	bool found = false;
	for(int i=m;i<=n;i++){
		fa[i]+=fa[i-1];

		if(!fa[i]){
			printf("%d\n",i);
			found=true;
			break;
		}
	}
	if(!found)printf("-1\n");
}