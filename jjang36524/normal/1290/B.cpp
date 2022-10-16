#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
string s;
int psum[200100][26];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	int l = s.size();
	int i,j;
	for (i = 1; i <= l; i++)
	{
		for (j = 0; j < 26; j++)
		{
			psum[i][j] = psum[i - 1][j] + (((s[i-1])-'a')==j);
		}
	}
	int Q;
	cin >> Q;
	while (Q--)
	{
		int a, b;
		cin >> a >> b;
		if (a == b)
		{
			cout << "Yes" << '\n';
			continue;
		}
		int c = 0;
		int j;
		for (j = 0; j < 26; j++)
		{
			if (psum[b][j] != psum[a - 1][j])
				c++;
		}
		if (c >= 3)
		{
			cout << "Yes" << '\n';
			continue;
		}
		else if (s[a-1] != s[b-1])
			cout << "Yes" << '\n';
		else
			cout << "No" << '\n';
	}
}