#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXK = -1;
const int MAXN = -1;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;

string inttostr(int x) {
	string res = "";
	res += (char)(x % 10 + '0');
	x /= 10;
	res += (char)(x % 10 + '0');
	x /= 10;
	reverse(res.begin(), res.end());
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int f;
	int a;
	char c;
	int b;
	while (cin >> f >> a >> c >> b) {
		string sa = inttostr(a);
		string sb = inttostr(b);

		int ans = 1e9;
		string res;
		//for (int hour = 0; hour < f; hour++) {
		for (int hour = (f == 12 ? 1 : 0); hour <= (f == 12 ? 12 : 23); hour++) {
			for (int minute = 0; minute < 60; minute++) {
				string ca = inttostr(hour);
				string cb = inttostr(minute);

				int cans = 0;
				for (int i = 0; i < 2; i++) {
					cans += ca[i] != sa[i];
					cans += cb[i] != sb[i];
				}
				if (ans > cans) {
					ans = cans;
					res = ca + ":" + cb;
				}
			}
		}
		cout << res << endl;
	}

	return 0;
}