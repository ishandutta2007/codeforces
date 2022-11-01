#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int a , b;
	cin >> a >> b;
	for(int i = a / 2 + a % 2 ; i <= a ; i++)
		if(i % b == 0)
		{
			cout << i;
			return 0;
		}
	cout << -1;
	return 0;
}