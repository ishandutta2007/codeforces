#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	string s;
	int n , x = 0;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> s;
		if(s[1] == '+')	x++;
		else	x--;
	}
	cout << x;
	return 0;
}