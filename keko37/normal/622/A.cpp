#include<iostream>

using namespace std;

long long n;

int main () {
	cin >> n;
	int x=1;
	while (n-x>0) {
		n-=x;
		x++;
	}
	cout << n;
	return 0;
}