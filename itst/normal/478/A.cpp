#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int a , b , c , d , e;
	cin >> a >> b >> c >> d >> e;
	if((a + b + c + d + e) % 5 || a + b + c + d + e < 5)	cout << -1;
	else	cout << (a + b + c + d + e) / 5;
	return 0;
}