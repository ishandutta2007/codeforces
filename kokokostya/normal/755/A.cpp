#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < 1001; i++) {
		bool is = 1;
		for (int j = 2; j < 1001; j++) {
			if (j < n * i + 1 && (n * i + 1) % j == 0)
				is = 0;
		}
		if (!is) {
			cout << i;
			return 0;
		}
	}
	return 0;
}