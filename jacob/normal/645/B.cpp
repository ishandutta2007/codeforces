#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	long long res = 0;
	while (n > 1 && k > 0) {
	  --k;
	  n -= 2;
	  res += n * 2 + 1;
	}
	cout << res << endl;
	return 0;
}