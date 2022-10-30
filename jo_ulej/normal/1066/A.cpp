#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

typedef long long int ll;

int main(int argc, char** argv)
{
	int t;
	cin >> t;

	for(int i = 0; i < t; ++i)
	{
		int L, v, l, r;

		cin >> L >> v >> l >> r;

		int ans = (L / v) - (r / v) + ((l - 1) / v);

		cout << ans << endl;
	}

	return 0;
}