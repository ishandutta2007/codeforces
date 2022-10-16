#include <iostream>
using namespace std;
int N;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	while (N--)
	{
		long long x, y;
		cin >> x >> y;
		if (x - y == 1)
			cout << "NO" << '\n';
		else
			cout << "YES" << '\n';
	}
}