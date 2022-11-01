#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int a , b , c , minN;
	cin >> a >> b >> c;
	if(a + b <= c)	cout << 2 * (a + b);
	else	if(a + c <= b)	cout << 2 * (a + c);
	else	if(c + b <= a)	cout << 2 * (b + c);
	else	cout << a + b + c;
	return 0;
}