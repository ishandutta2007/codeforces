#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;


int main() {
	int n;
	cin >> n;
	int t1, t2;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> t1 >> t2;
		ans = max(ans, t1 + t2);
	}
	cout << ans << "\n";
	//system("pause");
	return 0;
}