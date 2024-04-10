#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int n , num0 = 0 , num1 = 0;
	string s;
	cin >> n >> s;
	for(int i = 0 ; i < n ; i++)
		if(s[i] == '1')	num1++;
		else	num0++;
	cout << (int)abs(num1 - num0);
	return 0;
}