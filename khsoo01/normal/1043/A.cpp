#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 105;

ll n, a[N], mx, sum;

int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		mx = max(mx, a[i]);
		sum += a[i];
	}
	if(mx * n - sum > sum) printf("%lld\n",mx);
	else printf("%lld\n", mx+1+(sum - mx*n + sum)/n);
}