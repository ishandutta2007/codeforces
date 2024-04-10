#include<bits/stdc++.h>
#define R register int 
using namespace std;
long long n , k , ans , a[300000] , rest;
int main()
{
	cin >> n >> k;
	for(R i=1;i<=n;i++)
		cin >> a[i];
	for(R i=1;i<=n;i++){
		ans += a[i] / k;
		if(a[i] % k != 0){
			rest = a[i] % k;
			a[i + 1] = max(a[i + 1] - k + rest , 1ll * 0);
			ans++;
		}
	}
	cout<<ans;
	return 0;
}