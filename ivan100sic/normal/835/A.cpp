#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int s, v1, v2, t1, t2;

	cin >> s >> v1 >> v2 >> t1 >> t2;

	int r1 = 2*t1 + s*v1;
	int r2 = 2*t2 + s*v2;

	if (r1 < r2) {
		cout << "First\n";
	} else if (r1 > r2) {
		cout << "Second\n";
	} else {
		cout << "Friendship\n";
	}

}