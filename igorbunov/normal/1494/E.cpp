#include <algorithm>
#include <iostream>
#include <cstdlib>
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
 
using namespace std;

#define mod NE_mod
#define int long long
#define s second
#define f first
#define push_back emplace_back
#define endl "\n"

map<int, map<int, char>> kek;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	int cnt0 = 0;
	int cnt1 = 0;

	for (int i = 0; i < m; i++) {
		char type;
		cin >> type;
		if (type == '+') {
			int v, u;
			cin >> v >> u;
			v--;
			u--;
			char c;
			cin >> c;
			if (kek[u][v] >= 'a' && kek[u][v] <= 'z') {
				cnt0++;
				if (kek[u][v] == c) {
					cnt1++;
				}
			}
			kek[v][u] = c;
		}
		if (type == '-') {
			int v, u;
			cin >> v >> u;
			v--;
			u--;
			if (kek[u][v] >= 'a' && kek[u][v] <= 'z') {
				cnt0--;
				if (kek[u][v] == kek[v][u]) {
					cnt1--;
				}
			}
			kek[v][u] = 0;
		}
		if (type == '?') {
			int k;
			cin >> k;
			if (k % 2 == 1) {
				if (cnt0) {
					cout << "Yes\n";
				} else {
					cout << "No\n";
				}
			} else {
				if (cnt1) {
					cout << "Yes\n";
				} else {
					cout << "No\n";
				}
			}
		}
	}
}