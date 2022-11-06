#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{


	int n, x;
	cin >> n;
	x = 0;
	for (;n>0 ; n-=1)
	{
		string statement;
		cin >> statement;
		string cond0 = "X++";
		string cond1 = "++X";

		if ( statement == cond0 || statement == cond1)
		{
			x = x+1;
		}
		else
		{
			x=x-1;
		}
	}
	cout << x;
}