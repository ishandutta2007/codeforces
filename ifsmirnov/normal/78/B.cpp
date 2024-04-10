#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

string s="ROYGBIV";
string t;

int main()
{
	int n;
	cin >> n;
	t = s + string(n-7, 'a') + s;
	for (int i = 7; i < n; i++)
		for (int l = 0; l < 7; l++)
		{
			string p = t.substr(i-3, 7);
			if (count(p.begin(), p.end(), s[l]) == 0)
			{
				t[i] = s[l];
				break;
			}
		}
	cout << t.substr(0,n);
	return 0;	
};