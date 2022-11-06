#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
inline void cmin(ll &a,ll b){if(a>b)a=b;}
int main(){
	int n,t,i;ll s;
	scanf("%d",&n);t=n<<1;
	for(i=1;i<=t;++i)scanf("%I64d",&a[i]);
	sort(a+1,a+t+1);
	s=(a[n]-a[1])*(a[t]-a[n+1]);
	for(i=1;i< n;++i)cmin(s,(a[t]-a[1])*(a[i+n]-a[i+1]));
	printf("%I64d",s);
	return 0;
}