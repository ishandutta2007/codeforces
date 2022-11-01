#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int num25 = 0 , num50 = 0 , n;
	for(cin >> n ; n ; n--)
	{
		int a;
		cin >> a;
		switch(a)
		{
			case 25:
				num25++;
				break;
			case 50:
				if(!num25)
				{
					cout << "NO";
					return 0;
				}
				num50++;
				num25--;
				break;
			default:
				if(!num50)
				{
					if(num25 < 3)
					{
						cout << "NO";
						return 0;
					}
					num25 -= 3;
				}
				else
				{
					if(!num25)
					{
						cout << "NO";
						return 0;
					}
					num50--;
					num25--;
				}
		}
	}
	cout << "YES";
	return 0;
}