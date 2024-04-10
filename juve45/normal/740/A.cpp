#include <bits/stdc++.h>

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";\n"

using namespace std;
long long n, a, b, c, ans = 1000000000000LL;
int main()
{
	ios_base::sync_with_stdio(false);

	cin>>n;
	if(n%4 == 0)
	{
		 cout << 0;
		 return 0;
	}
	cin >> a >> b >> c;

	long long x[100];

	x[0] = 0;
	x[1] = a;
	x[2] = b;
	x[3] = c;

	for(int i=1;i<80;i++)
	{
		x[i] = 1000000000000000LL;
		if(i>0) 
		x[i] = min(x[i-1] + a, x[i]);
		if(i>1) 
		x[i] = min(x[i-2] + b, x[i]);
		if(i>2) 
		x[i] = min(x[i-3] + c, x[i]);

		if((n+i) % 4 ==0)
			ans = min(x[i], ans);
	}
	cout << ans << '\n';

	return 0;
}