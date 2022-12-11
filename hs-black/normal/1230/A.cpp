#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main() {
	int a1, a2, a3, a4;
	cin >> a1 >> a2 >> a3 >> a4;
	int sum = a1 + a2 + a3 + a4;
	if (sum % 2) {
		cout << "NO\n";
		return 0;
	}
	sum /= 2;
	if (a1 + a2 == sum || a1 + a3 == sum || a1 + a4 == sum) {
		cout << "YES" << endl;
		return 0;
	}
	if (a1 == sum || a2 == sum || a3 == sum || a4 == sum) {
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO\n";
	return 0;
}