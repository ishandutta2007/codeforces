#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	string a, b;
	cin >> n >> a >> b;
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i])
			continue;
		if (i < n && a[i] == b[i + 1] && a[i + 1] == b[i]) {
			c++; i++;
		}
		else if (a[i] != b[i]) c++;
	}
	cout << c << '\n';
	return 0;
}