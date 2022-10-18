#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n % 3 == 0){
		cout << n / 3 * 2;
	}
	else{
		cout << n / 3 * 2 + 1;
	}
	return 0;
}