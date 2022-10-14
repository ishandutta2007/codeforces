#include<iostream>

using namespace std;

int n, k;

int main () {
	cin >> n >> k;
	int ost = n % (2*k+1);
	int x = n / (2*k+1) + !!ost;
	cout << x << endl;
	int curr = k+1;
	if (0 < ost && ost < k+1) curr -= (k+1 - ost);
	for (; curr <= n; curr += 2*k+1) {
		cout << curr << " ";
	}
	return 0;
}