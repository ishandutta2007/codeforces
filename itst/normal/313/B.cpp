#include<bits/stdc++.h>
using namespace std;
int num[100001];
int main()
{
	string s;
	cin >> s;
	for(int i = 2 ; i <= s.size() ; i++)
		num[i] = num[i - 1] + (s[i - 1] == s[i - 2]);
	int n;
	for(cin >> n ; n ; n--)
	{
		int a , b;
		cin >> a >> b;
		cout << num[b] - num[a] << endl;
	}
	return 0;
}