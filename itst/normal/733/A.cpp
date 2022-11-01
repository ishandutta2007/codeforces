#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	string s;
	int nowP = -1 , maxN = 0;
	cin >> s;
	for(int i = 0 ; i < s.size() ; i++)
		if(s[i] == 'Y' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
		{
			maxN = max(i - nowP , maxN);
			nowP = i;
		}
	cout << max(maxN , (int)strlen(s.c_str()) - nowP);
	return 0;
}