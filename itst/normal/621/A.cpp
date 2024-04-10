#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	long long n , sum = 0 , minOdd = 9999999999;
	for(cin >> n ; n ; n--)
	{
		int a;
		cin >> a;
		sum += a;
		if(a % 2 && a < minOdd)	minOdd = a;
	}
	if(sum % 2)	cout << sum - minOdd;
	else	cout << sum;
	return 0;
}