#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	if(n == 1)
	{
		int a;
		cin >> a;
		if(a == 0)	cout << "UP";
		else	if(a == 15)	cout << "DOWN";
		else	cout << -1;
	}
	else
	{
		int a , b;
		for(int i = 0 ; i < n - 1 ; i++)	cin >> a;
		cin >> b;
		if(a < b && b != 15 || a > b && b == 0)	cout << "UP";
		else	cout << "DOWN";
	}
	return 0;
}