#include <bits/stdc++.h>
#define x first
#define y second

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";" << endl;
#define DMAX 1000009
using namespace std;

long long n, k;
string s;

inline long long l2(long long k)
{
	return (((k^(k-1))+1)>>1);
}
long long aib[DMAX];


void inc(long long pos)
{
	for(long long i=pos;i<=DMAX;i+=l2(i))
	{
		aib[i]++;
	}
}

long long que(long long pos)
{
	long long ans = 0;
	for(long long i=pos;i>0;i-=l2(i))
	{
		ans += aib[i];
	}
	return ans;
}



int main()
{
	ios_base::sync_with_stdio(false);
	
	cin >> n >> k;
	if(k>n/2) k=n-k;
	long long x = 1;
	long long ans = 1;
	for(long long i=1;i<=n;i++)
	{
		long long x2 = x+k;
		if(x2 > n)
			x2-=n;
		ans++;

			if(x2 < x) ans += 2LL*(i-1) - (que(x) - que(x2-1));
			else ans += 1LL*que(x2-1) - 1LL*que(x);
	
		inc(x);
		inc(x2);
		x=x2;
	cout << ans << ' ';
	}




	return 0;
}