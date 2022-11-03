#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <iomanip>
#include <deque>
#include <stack>
#include <cmath>
#include <unordered_set>

using namespace std;

//inline void operator delete (void *) {};

typedef long long ll;

const int MAX_N = 110;

int n;
int a[MAX_N];

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	vector < int >l(n), r(n);

	for (int i = 0; i < n; i++)
		cin >> l[i] >> r[i];

	vector < int > L, R;

	for (int i = 0; i < n; i++) {
		if (l[i])
			continue;
		L.push_back(i);
		int v = i;
		while (r[v])
			v = r[v] - 1;
		R.push_back(v);
	}

	for (int j = 0; j < L.size() - 1; j++) {
		l[L[j]] = R[j + 1] + 1;
		r[R[j + 1]] = L[j] + 1;
	}

	for (int i = 0; i < n; i++)
		cout << l[i] << ' ' << r[i] << '\n';

	return 0;
}