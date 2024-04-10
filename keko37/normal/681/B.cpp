#include<iostream>

using namespace std;
typedef long long int llint;

llint n;

int main () {
	cin >> n;
	for (llint i=0; i<=811; i++) {
		for (llint j=0; j<=8101; j++) {
			llint x=n-i*1234567-j*123456;
			if (x>=0 && x%1234==0) {
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}