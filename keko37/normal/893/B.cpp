#include<iostream>
#include<cmath>

using namespace std;

int n;

int main () {
	cin >> n;
	for (int i=10; i>=1; i--) {
		int t=(pow(2, i)-1)*pow(2, i-1);
		if (n%t==0) {
			cout << t;
			return 0;
		}
	}
	return 0;
}