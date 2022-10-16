#include <iostream>
using namespace std;
int N;
int main()
{
	cin >> N;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (N--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (c % 3 == 0)
			cout << a << '\n';
		if (c % 3 == 1)
			cout << b << '\n';
		if (c % 3 == 2)
			cout << (a ^ b) << '\n';
	}
}