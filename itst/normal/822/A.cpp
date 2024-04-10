#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int a , b;
	cin >> a >> b;
	a = a > b ? b : a;
	b = 1;
	for(int i = 2 ; i <= a ; i++)	b *= i;
	cout << b;
	return 0;
}