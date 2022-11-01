#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a , b , c , d;
	cin >> a >> b >> c >> d;
	if(a == c)	cout << a - b + d << " " << b << " " << c - b + d << " " << d;
	else	if(b == d)	cout << a << " " << b - a + c << " " << c << " " << d - a + c;
	else	if(a - c == b - d || a - c == d - b)	cout << a << " " << d << " " << c << " " << b;
	else	cout << -1;
	return 0;
}