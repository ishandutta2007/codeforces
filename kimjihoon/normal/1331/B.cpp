#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n; cin >> n;
	for (int i = 2; i <= n; i++)
		if (n % i == 0) {
			cout << i << n / i << '\n';
			break;
		}
	return 0;
}