#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,a,b,c,d;
	cin >> n >> a >> b >> c >> d;
	int x;
	long long ans=0;
	int mn,mx;
	mn = min(a,d)+min(b,c);
	mx = max(a,d)+max(b,c);
	if(mx+1-mn<=n){
		ans=n*1LL*(n-mx+mn);
	}else{
		ans = 0;
	}
	cout << ans;
	return 0;
}