#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int n , t;
	string s , s1;
	cin >> n >> t >> s;
	s1 = s;
	bool f = 1;
	while(f && t)
	{
		f = 0;
		t--;
		for(int i = 1 ; i <= n - 1 ; i++)
			if(s[i] == 'G' && s[i - 1] == 'B')
			{
				f = 1;
				s1[i] = 'B';
				s1[i - 1] = 'G';
			}
		s = s1;
	}
	cout << s;
	return 0;
}