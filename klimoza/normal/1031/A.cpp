#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cmath>

using namespace std;



int main() {
	int w, h, k;
	cin >> w >> h >> k;
	int ans = 0;
	w -= 2;
	for (int i = 0; i < k; i++) {
		ans += 2 * w + 2 * h;
		w -= 4;
		h -= 4;
	}
	cout << ans << "\n";
	//system("pause");
	return 0;
}