#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a , b , c , d , e , f , g;
	cin >> a >> b >> c >> d >> e >> f >> g;
	if((a + b + c) / 5 + ((a + b + c) % 5 ? 1 : 0) + (d + e + f) / 10 + ((d + e + f) % 10 ? 1 : 0) <= g)
		cout << "YES";
	else	cout << "NO";
	return 0;
}