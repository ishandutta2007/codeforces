#include <iostream>

using namespace std;

int a[100];
int main() {
	int n;
	cin >> n;
	int ah = 99999, ai, bh = 0, bi;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] <= ah) {
			ah = a[i];
			ai = i;
		}
		if (a[i] > bh) {
			bh = a[i];
			bi = i;
		}
	}
	cout << bi+n-1-ai-(bi > ai) << endl;
	return 0;
}