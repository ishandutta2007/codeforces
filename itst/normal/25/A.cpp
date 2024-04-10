#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int n , a , b , c;
	cin >> n >> a >> b;
	if(a % 2 == b % 2)
		for(int i = 3 ; i <= n ; i++)
		{
			cin >> c;
			if(c % 2 != a % 2)
			{
				cout << i;
				return 0;
			}
		}
	else
	{
		cin >> c;
		if(c % 2 == a % 2)	cout << 2;
		else	cout << 1;
	}
	return 0;
}