#include<bits/stdc++.h>
using namespace std;
inline bool ifC(int a)
{
	bool num[10] = {};
	while(a)
	{
		if(num[a % 10])	return false;
		num[a % 10] = 1;
		a /= 10;
	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	while(!ifC(++n));
	cout << n;
	return 0;
}