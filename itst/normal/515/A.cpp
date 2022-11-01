#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int a , b , c;
	cin >> a >> b >> c;
	if(a < 0)	a = -a;
	if(b < 0)	b = -b;
	if(a + b <= c && (c - a - b) % 2 == 0)	cout << "YES";
	else	cout << "NO";
	return 0;
}