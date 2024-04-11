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


int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector< vector<char> > a(n, vector<char>(7));
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 7; j++)
			cin >> a[i][j];
	}
	int mx = 0;
	for (int j = 0; j < 7; j++){
		int val = 0;
		for (int i = 0; i < n; i++)
			val += a[i][j] - '0';
		mx = max(mx, val);
	}
	cout << mx;
	return 0;
}