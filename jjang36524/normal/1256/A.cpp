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
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		int left = d % c;
		if (a * c + b < d || left > b)
			cout << "no";
		else
			cout << "yes";
		cout << '\n';
	}
}