#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int a , b;
	for(cin >> a >> b ; a ; a--)
		for(int i = 0 ; i < b ; i++)
		{
			char c;
			cin >> c;
			if(c == 'C' || c == 'M' || c == 'Y')
			{
				cout << "#Color";
				return 0;
			}
		}
	cout << "#Black&White";
	return 0;
}