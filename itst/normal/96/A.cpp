#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	string s;
	cin >> s;
	for(int i = 0 ; i + 7 <= s.size() ; i++)
		if(string(s , i , 7) == string(7 , '1') || string(s , i , 7) == string(7 , '0'))
		{
			cout << "YES";
			return 0;
		}
	cout << "NO";
	return 0;
}