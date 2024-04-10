#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int k , n , w;
	cin >> k >> n >> w;
	cout << (n - (w + 1) * w / 2 * k >= 0 ? 0 : (w + 1) * w / 2 * k - n);
	return 0;
}