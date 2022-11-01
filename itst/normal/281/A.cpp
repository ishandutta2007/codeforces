#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	string s;
	cin >> s;
	s[0] = s[0] >= 'a' && s[0] <= 'z' ? s[0] - 'a' + 'A' : s[0];
	cout << s;
	return 0;
}