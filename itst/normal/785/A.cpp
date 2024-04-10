#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n , tot = 0;
	for(cin >> n ; n ; n--)
	{
		string s;
		cin >> s;
		switch(s[0])
		{
			case 'T':
				tot += 4;
				break;
			case 'C':
				tot += 6;
				break;
			case 'O':
				tot += 8;
				break;
			case 'D':
				tot += 12;
				break;
			case 'I':
				tot += 20;
		}
	}
	cout << tot;
	return 0;
}