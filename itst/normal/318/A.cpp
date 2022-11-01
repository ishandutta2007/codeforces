#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	long long k , n;
	cin >> n >> k;
	if(k <= n / 2 + n % 2)	cout << 2 * k - 1;
	else	cout << (k - n / 2 - n % 2) * 2;
	return 0;
}