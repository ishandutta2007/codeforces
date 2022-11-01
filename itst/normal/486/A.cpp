#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	long long n;
	cin >> n;
	cout << (n % 2 ? -1 : 1) * (n + 1) / 2;
	return 0;
}