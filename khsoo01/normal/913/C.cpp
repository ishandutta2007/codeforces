#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k, a[35], v[35], cur, ans;

int main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=30;i++) {
		if(a[i] == 0) a[i] = 2*a[i-1];
		else a[i] = min(a[i], 2*a[i-1]);
	}
	for(int i=0;i<=30;i++) {
		v[i] = k%2; k /= 2;
		cur += v[i] * a[i];
	}
	ans = cur;
	for(int i=0;i<=30;i++) {
		if(v[i] == 0) ans = min(ans, cur+a[i]);
		cur -= v[i] * a[i];
	}
	printf("%lld\n",ans);
}