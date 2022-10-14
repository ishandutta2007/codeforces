#include<iostream>

using namespace std;

int k, cnt;

int ok (int x) {
	int sum=0;
	while (x) {
		sum+=x%10;
		x/=10;
	}
	return (sum==10);
}

int main () {
	cin >> k;
	for (int i=1; i<1e8; i++) {
		if (ok(i)) cnt++;
		if (cnt==k) {
			cout << i;
			break;
		}
	}
	return 0;
}