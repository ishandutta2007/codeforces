#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	for(cin >> n ; n ; n--)
	{
		int a;
		cin >> a;
		if(a == 1)
		{
			cout << -1;
			return 0;
		}
	}
	cout << 1;
	return 0;
}