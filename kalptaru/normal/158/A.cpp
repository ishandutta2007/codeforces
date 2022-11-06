#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	int n,k;
	cin >> n >> k;
	int a[n+1];
	for (int i = 1; i<=n ; ++i)
	{
		cin >> a[i];
	}
	int k_value = a[k];
	int count  = 1;
	int result = 0;
	for (;count <= n ; count++ )
		{
			if( a[count] >= k_value && a[count] > 0)
				result = result+1;
		}
		cout << result;
}