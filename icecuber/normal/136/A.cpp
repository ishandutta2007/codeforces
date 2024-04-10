#include <iostream>

using namespace std;

int a[100];
int main() {
	int n, tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		a[tmp-1] = i+1;
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << (i == n-1?"\n":" ");
	}
	return 0;
}