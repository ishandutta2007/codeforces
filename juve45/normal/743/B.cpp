#include <bits/stdc++.h>
#define x first
#define y second

#define dbg(x) cout << "Debugger -> " << #x << " = " << x << ";" << endl;

using namespace std;

long long n, k;

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> n >> k;

	long long ans = 1;
	while(k%2==0)
	{
		k=k/2;
		ans++;
	}
	cout << ans;

	return 0;
}