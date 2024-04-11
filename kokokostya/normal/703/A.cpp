#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int res1 = 0, res2 = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b)
			res1++;
		if (b > a)
			res2++;
	}
	if (res1 > res2)
		cout << "Mishka";
	if (res2 > res1)
		cout << "Chris";
	if (res1 == res2)
		cout << "Friendship is magic!^^";
	return 0;
}