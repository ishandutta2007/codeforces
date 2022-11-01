#include<bits/stdc++.h>
using namespace std;
int num[30001];
int main()
{
	std::ios::sync_with_stdio(false);
	int n , t , i = 1;
	cin >> n >> t;
	for(int i = 1 ; i < n ; i++)	cin >> num[i];
	num[n] = 1000;
	while(i <= n)
	{
		if(i == t)
		{
			cout << "YES";
			return 0;
		}
		i += num[i];
	}
	cout << "NO";
	return 0;
}