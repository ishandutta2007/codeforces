#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int a , b;
	cin >> a >> b;
	if(a == 1)
		if(b == 10)	cout << -1;
		else	cout << b;
	else
		if(b == 10)
		{
			cout << 1;
			for(int i = 1 ; i < a ; i++)	cout << 0;
		}
		else	for(int i = 0 ; i < a ; i++)	cout << b;
	return 0;
}