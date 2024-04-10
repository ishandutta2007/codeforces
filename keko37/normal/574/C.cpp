#include<iostream>

using namespace std;

int n;
int l[100005];

int f (int x) {
	while (x%2==0) x/=2;
	while (x%3==0) x/=3;
	return x;
}

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> l[i];
	}
	int bla=f(l[0]);
	for (int i=0; i<n; i++) {
		if (f(l[i])!=bla) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}