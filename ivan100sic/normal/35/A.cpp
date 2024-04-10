// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");

	int x;
	cin >> x;
	int k = 3;
	while (k--) {
		int a, b;
		cin >> a >> b;
		if (x == a || x == b)
			x = a+b-x;
	}

	cout << x << "\n";

}