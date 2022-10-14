#include<iostream>

using namespace std;

int n, x, curr=3;

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x;
		if (x==curr) {
			cout << "NO";
			return 0;
		}
		if (x==1) {
			if (curr==2) curr=3; else curr=2;
		} else if (x==2) {
			if (curr==1) curr=3; else curr=1;
		} else {
			if (curr==1) curr=2; else curr=1;
		}
	}
	cout << "YES";
	return 0;
}