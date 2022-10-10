#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 2020;

int a[ms][ms];
int b[ms][ms];
int col[ms], row[ms];
int c[ms];

int get(int i, int j) { return a[i][j] ^ (row[i] ? c[j] : 0) ^ (col[j] ? c[i] : 0); }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			char ch;
			std::cin >> ch;
			a[i][j] = ch - '0';
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			char ch;
			std::cin >> ch;
			b[i][j] = ch - '0';
		}
	}
	for(int i = 0; i < n; i++) {
		char ch;
		std::cin >> ch;
		c[i] = ch - '0';
	}
	for(int rep = 0; rep < 2; rep++) {
		for(int j = 0; j < n; j++) {
			if(get(0, j) != b[0][j]) {
				col[j] ^= 1;
			}
		}
		for(int i = 1; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(get(i, j) != b[i][j]) {
					row[i] ^= 1;
				}
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(get(i, j) != b[i][j]) {
					col[j] ^= 1;
				}
			}
		}
		for(int i = 1; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(get(i, j) != b[i][j]) {
					row[i] ^= 1;
				}
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(get(i, j) != b[i][j]) {
					col[j] ^= 1;
				}
			}
		}
		bool valid = true;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				valid = valid && get(i, j) == b[i][j];
			}
		}
		if(valid) {
			std::vector<std::pair<std::string, int>> ans;
			for(int i = 0; i < n; i++) {
				if(row[i]) {
					ans.emplace_back("row", i);
				}
				if(col[i]) {
					ans.emplace_back("col", i);
				}
			}
			std::cout << ans.size() << '\n';
			for(auto p : ans) {
				std::cout << p.first << ' ' << p.second << '\n';
			}
			return 0;
		}
		row[0] ^= 1;
	}
	std::cout << "-1\n";
}