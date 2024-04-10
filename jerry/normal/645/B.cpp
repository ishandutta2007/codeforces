#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n, k; cin >> n >> k;
	k = min(k, n>>1)<<1;
	cout << (k*(k-1)>>1)+k*(n-k) << endl;
	return 0;
}