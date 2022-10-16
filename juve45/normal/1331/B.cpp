#include <iostream>


using namespace std;

int n;
int main() {
	cin >> n;

	int x = 2;
	while(n >= x) {
		while(n % x == 0) cout << x, n /= x;
		x++;
	}
	
}