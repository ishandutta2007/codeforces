#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int read_one(int n, vector<vector<int>>& a, int r, int c) {
	cin >> a[r][c];
	return 0;
}

int read_row(int n, vector<vector<int>>& a, int r) {
	n > 0 ? read_one(n, a, r, 0) : 0;
	n > 1 ? read_one(n, a, r, 1) : 0;
	n > 2 ? read_one(n, a, r, 2) : 0;
	n > 3 ? read_one(n, a, r, 3) : 0;
	n > 4 ? read_one(n, a, r, 4) : 0;
	n > 5 ? read_one(n, a, r, 5) : 0;
	n > 6 ? read_one(n, a, r, 6) : 0;
	n > 7 ? read_one(n, a, r, 7) : 0;
	n > 8 ? read_one(n, a, r, 8) : 0;
	n > 9 ? read_one(n, a, r, 9) : 0;

	return 0;
}

int read_all(int n, vector<vector<int>>& a) {
	n > 0 ? read_row(n, a, 0) : 0;
	n > 1 ? read_row(n, a, 1) : 0;
	n > 2 ? read_row(n, a, 2) : 0;
	n > 3 ? read_row(n, a, 3) : 0;
	n > 4 ? read_row(n, a, 4) : 0;
	n > 5 ? read_row(n, a, 5) : 0;
	n > 6 ? read_row(n, a, 6) : 0;
	n > 7 ? read_row(n, a, 7) : 0;
	n > 8 ? read_row(n, a, 8) : 0;
	n > 9 ? read_row(n, a, 9) : 0;

	return 0;
}

int fw_loop4(int n, vector<vector<int>>& a, int k, int i, int j) {
	a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
	return 0;
}

int fw_loop3(int n, vector<vector<int>>& a, int k, int i) {
	n > 0 ? fw_loop4(n, a, k, i, 0) : 0;
	n > 1 ? fw_loop4(n, a, k, i, 1) : 0;
	n > 2 ? fw_loop4(n, a, k, i, 2) : 0;
	n > 3 ? fw_loop4(n, a, k, i, 3) : 0;
	n > 4 ? fw_loop4(n, a, k, i, 4) : 0;
	n > 5 ? fw_loop4(n, a, k, i, 5) : 0;
	n > 6 ? fw_loop4(n, a, k, i, 6) : 0;
	n > 7 ? fw_loop4(n, a, k, i, 7) : 0;
	n > 8 ? fw_loop4(n, a, k, i, 8) : 0;
	n > 9 ? fw_loop4(n, a, k, i, 9) : 0;

	return 0;
}

int fw_loop2(int n, vector<vector<int>>& a, int k) {
	n > 0 ? fw_loop3(n, a, k, 0) : 0;
	n > 1 ? fw_loop3(n, a, k, 1) : 0;
	n > 2 ? fw_loop3(n, a, k, 2) : 0;
	n > 3 ? fw_loop3(n, a, k, 3) : 0;
	n > 4 ? fw_loop3(n, a, k, 4) : 0;
	n > 5 ? fw_loop3(n, a, k, 5) : 0;
	n > 6 ? fw_loop3(n, a, k, 6) : 0;
	n > 7 ? fw_loop3(n, a, k, 7) : 0;
	n > 8 ? fw_loop3(n, a, k, 8) : 0;
	n > 9 ? fw_loop3(n, a, k, 9) : 0;

	return 0;
}

int fw_loop1(int n, vector<vector<int>>& a) {
	n > 0 ? fw_loop2(n, a, 0) : 0;
	n > 1 ? fw_loop2(n, a, 1) : 0;
	n > 2 ? fw_loop2(n, a, 2) : 0;
	n > 3 ? fw_loop2(n, a, 3) : 0;
	n > 4 ? fw_loop2(n, a, 4) : 0;
	n > 5 ? fw_loop2(n, a, 5) : 0;
	n > 6 ? fw_loop2(n, a, 6) : 0;
	n > 7 ? fw_loop2(n, a, 7) : 0;
	n > 8 ? fw_loop2(n, a, 8) : 0;
	n > 9 ? fw_loop2(n, a, 9) : 0;

	return 0;
}

int sol(int n, vector<vector<int>>& a) {
	int sol = 0;
	sol = max(sol, n > 0 ? *max_element(a[0].begin(), a[0].end()) : 0);
	sol = max(sol, n > 1 ? *max_element(a[1].begin(), a[1].end()) : 0);
	sol = max(sol, n > 2 ? *max_element(a[2].begin(), a[2].end()) : 0);
	sol = max(sol, n > 3 ? *max_element(a[3].begin(), a[3].end()) : 0);
	sol = max(sol, n > 4 ? *max_element(a[4].begin(), a[4].end()) : 0);
	sol = max(sol, n > 5 ? *max_element(a[5].begin(), a[5].end()) : 0);
	sol = max(sol, n > 6 ? *max_element(a[6].begin(), a[6].end()) : 0);
	sol = max(sol, n > 7 ? *max_element(a[7].begin(), a[7].end()) : 0);
	sol = max(sol, n > 8 ? *max_element(a[8].begin(), a[8].end()) : 0);
	sol = max(sol, n > 9 ? *max_element(a[9].begin(), a[9].end()) : 0);
	return sol;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, i, j;
	vector<vector<int>> a;

	cin >> n;
	a.resize(n, vector<int>(n, 0));

	read_all(n, a);
	fw_loop1(n, a);
	cout << sol(n, a);
}