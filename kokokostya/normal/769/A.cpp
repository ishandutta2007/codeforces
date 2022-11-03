#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <vector>	
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <algorithm>
#include <stack>
#include <complex>

using namespace std;

int main() {
	//freopen("integral.in", "r", stdin);
	//freopen("integral.out", "w", stdout);
	iostream::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	cout << a[n / 2];
	return 0;
}