#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int k;
	cin >> k;
	if (k == 0)
		cout << 'a';
	char res = 'a';
	while (k) {
		int now = 1;
		while (now * 1ll * (now - 1) <=2 * k)
			now++;
		now--;
		k -= now * 1ll * (now - 1) / 2;
		for (int i = 0; i < now; i++)
			cout << res;
		res++;
	}
	return 0;
}