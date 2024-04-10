#include<bits/stdc++.h>
using namespace std;
bool num[26];
int main()
{
	std::ios::sync_with_stdio(false);
	string s;
	cin >> s;
	for(int i = 0 ; i < s.size() ; i++)	num[s[i] - 'a'] = 1;
	int a = 0;
	for(int i = 0 ; i < 26 ; i++)	a += num[i];
	if(a % 2 == 0)	cout << "CHAT WITH HER!";
	else	cout << "IGNORE HIM!";
	return 0;
}