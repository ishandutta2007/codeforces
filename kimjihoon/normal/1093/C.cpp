#include <iostream>
using namespace std;
#define ll long long

ll b[200009], a[400009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n / 2; i++)
		cin >> b[i];
	ll s = 0, e = b[0];
	for (int i = 0; i < n / 2; i++) {
		int ri = n - i - 1;
		if (b[i] - s <= e)
			e = b[i] - s;
		else
			s = b[i] - e;
		a[i] = s; a[ri] = e;
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << '\n';
	return 0;
}