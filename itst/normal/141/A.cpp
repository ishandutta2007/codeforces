#include<bits/stdc++.h>
using namespace std;
int vis[26];
int main()
{
	std::ios::sync_with_stdio(false);
	string s1 , s2 , s3;
	cin >> s1 >> s2 >> s3;
	if(s1.size() + s2.size() != s3.size())
	{
		cout << "NO";
		return 0;
	}
	for(int i = 0 ; i < s1.size() ; i++)
		vis[s1[i] - 'A']++;
	for(int i = 0 ; i < s2.size() ; i++)
		vis[s2[i] - 'A']++;
	for(int i = 0 ; i < s3.size() ; i++)
		if(--vis[s3[i] - 'A'] < 0)
		{
			cout << "NO";
			return 0;
		}
	cout << "YES";
	return 0;
}