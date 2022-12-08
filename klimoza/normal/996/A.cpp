#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <cmath>

using namespace std;



int main() {
	int n;
	cin >> n;
	int ans = 0;
	ans += n / 100;
	n = n % 100;
	ans += n / 20;
	n = n % 20;
	ans += n / 10;
	n = n % 10;
	ans += n / 5;
	n = n % 5;
	ans += n;
	cout << ans << "\n";
	//system("pause");
	return 0;
}