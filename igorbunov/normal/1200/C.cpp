#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
 
#pragma GCC_OPTIMIZE("ofast")

using namespace std;
 

#define int long long
#define endl "\n"

int gcd(int a, int b) {
	if (!b) {
		return a;
	}

	return gcd(b, a % b);
}

signed main() {
	int a, b;
	cin >> a >> b;

	int c = gcd(a, b);

	int q;
	cin >> q;

	for (int i = 0; i < q; i++) {
		int s1, s2, e1, e2;
		cin >> s1 >> s2 >> e1 >> e2;
		s2--;
		e2--;
		int now1, now2;

		if (s1 == 1) {
			now1 = s2 / (a / c);
		} else {
			now1 = s2 / (b / c);
		}

		if (e1 == 1) {
			now2 = e2 / (a / c);
		} else {
			now2 = e2 / (b / c);
		}

		//cout << now1 << " " << now2;

		if (now1 == now2) {
			cout << "YES";
		} else {
			cout << "NO";
		}

		cout << endl;


	}
}