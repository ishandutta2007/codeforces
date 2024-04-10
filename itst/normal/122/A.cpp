#include<bits/stdc++.h>
using namespace std;
inline bool ifL(int a)
{
	while(a)
	{
		if(a % 10 - 4 && a % 10 - 7)	return false;
		a /= 10;
	}
	return true;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 2 ; i <= n ; i++)
		if(n % i == 0 && ifL(i))
		{
			cout << "YES";
			return 0;
		}
	cout << "NO";
	return 0;
}