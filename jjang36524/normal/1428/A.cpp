#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;
int main()
{
	int N;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	while (N--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int ans = abs(a - c) + abs(b - d);
		if (a != c && b != d)
			ans += 2;
		cout << ans << '\n';
	}
}