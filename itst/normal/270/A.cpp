#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int t;
	for(cin >> t ; t ; t--)
	{
		int a;
		cin >> a;
		if(360 % (180 - a))	cout << "NO" << endl;
		else	cout << "YES" << endl;
	}
	return 0;
}