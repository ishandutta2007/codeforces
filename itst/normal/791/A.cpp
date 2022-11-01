#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int a , b , i;
	cin >> a >> b;
	for(i = 0 ; a <= b ; i++)
	{
		a *= 3;
		b *= 2;
	}
	cout << i;
	return 0;
}