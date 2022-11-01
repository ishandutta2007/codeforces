#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a , b , c , d , maxN = 0;
	cin >> a >> b >> c >> d;
	c = min(c , d);
	for(int i = min(a , b) ; i + 1 ; i--)
		maxN = max(maxN , i * 32 + min(a - i , c) * 256);
	cout << maxN;
	return 0;
}