#include <bits/stdc++.h>

bool query(int x, int y) {
	std::cout << 1 << " " << x << " " << y << std::endl;
	std::string s;
	std::cin >> s;
	return s == "TAK";
}

int solve(int l, int r) {
	if (l == r) {
		return l;
	}
	int mid = (l + r) >> 1;
	if (query(mid, mid + 1)) {
		return solve(l, mid);
	} else {
		return solve(mid + 1, r);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	
	int n, k;
	std::cin >> n >> k;
	int x = solve(1, n);
	int y = x < n ? solve(x + 1, n) : x;
	if (query(y, x) && y != x) {
		std::cout << 2 << " " << x << " " << y << std::endl;
	} else {
		y = x > 1 ? solve(1, x - 1) : x;
		std::cout << 2 << " " << x << " " << y << std::endl;
	}
}