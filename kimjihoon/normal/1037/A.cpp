#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	long long n, c = 0, t = 1;
	cin >> n;
	while (n > t - 1) {
		t *= 2; c++;
	}
	cout << c << '\n';
	return 0;
}