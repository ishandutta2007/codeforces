#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	long long sum = 0;
	int n;
	cin >> n;
	for(int i = 1 ; i <= n ; i++)	sum += i * (n - i) + 1;
	cout << sum;
	return 0;
}