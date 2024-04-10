#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int n , m , a , b;
	cin >> n >> m >> a >> b;
	if(a * m <= b)	cout << a * n;
	else	cout << n / m * b + (n % m * a > b ? b : n % m * a);
	return 0;
}