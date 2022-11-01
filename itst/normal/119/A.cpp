#include<bits/stdc++.h>
using namespace std;
int gcd(int a , int b)
{
	return a % b ? gcd(b , a % b) : b;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int a , b , c , i = 1;
	cin >> a >> b >> c;
	while(c)	c -= gcd(i++ % 2 ? a : b , c);
	cout << i % 2;
	return 0;
}