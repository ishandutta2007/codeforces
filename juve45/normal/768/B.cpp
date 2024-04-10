#include <bits/stdc++.h>

#define dbg(x) cerr<<#x": "<<x<<"\n"
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(long long _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"


using namespace std;
long long n,b[66], l, r;

long long cnt(long long k)
{
	long long ans =0;
	while(k%2==0) k/=2, ans++;
	return ans;
}

int main()
{
	cin >> n >> l >> r;
	long long nn= n;
	long long i;

	for(i=0;nn;i++, nn/=2)
		b[i]=nn%2;

	reverse(b, b+i);
	long long ans = 0;

	for(long long i=l;i<=r;i++)
	{
		long long x = cnt(i);
		ans += b[x];
	}
	cout << ans;
	//dbg_v(b, i);


}