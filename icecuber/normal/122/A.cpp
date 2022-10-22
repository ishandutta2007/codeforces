#include <iostream>

using namespace std;

int l[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};

int main() {
	int n;
	cin >> n;
	int ok = 0;
	for (int i = 0; i < 14; i++)
		if (n%l[i] == 0) ok = 1;
	cout << (ok?"YES\n":"NO\n");
	return 0;
}