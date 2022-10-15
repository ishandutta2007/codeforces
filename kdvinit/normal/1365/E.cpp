#include <iostream>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 505;

int n;
int a[N];

int32_t main()
{
	IOS;
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j++)
			for(int k = j; k <= n; k++)
				ans = max(ans, (a[i] | a[j] | a[k]));
	cout << ans;
	return 0;
}