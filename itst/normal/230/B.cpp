#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	for(cin >> n ; n ; n--)
	{
		long long a;
		cin >> a;
		if(sqrt(a) == (int)sqrt(a) && a - 1)
		{
			int k = (int)sqrt(a) , f = 1;
			for(int i = 2 ; i * i <= k && f ; i++)
				if(k % i == 0)	f = 0;
			if(f)	cout << "YES" << endl;
			else	cout << "NO" << endl;
		}
		else	cout << "NO" << endl;
	}
	return 0;
}