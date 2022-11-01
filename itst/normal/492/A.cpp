#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int n , i = 0;
	cin >> n;
	while(n >= 0)	n -= ++i * (i + 1) / 2;
	cout << --i;
	return 0;
}