#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int n , c = 0;
	for(cin >> n ; n ; n--)
	{
		int a , b;
		cin >> a >> b;
		if(b - a >= 2)	c++;
	}
	cout << c;
	return 0;
}