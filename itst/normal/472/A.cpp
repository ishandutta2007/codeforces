#include<bits/stdc++.h>
using namespace std;
bool ifZ(int a)
{
	for(int i = 2 ; i * i <= a ; i++)
		if(a % i == 0)	return false;
	return true;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 4 ; i <= n / 2 ; i++)
		if(!ifZ(i) && !ifZ(n - i))
		{
			cout << i << " " << n - i;
			return 0;
		}
	return 0;
}