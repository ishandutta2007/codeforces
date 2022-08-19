#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int n;
vector<vector<int>> answer;

int main() {
	scanf("%d", &n);
	int deg = 2 * n;
	for (int i = 1; i <= n; i++) {
		answer.push_back(vector<int> {i, i % n + 1});
	}
	auto isprime = [&](int x) {
		for (int i = 2; i < x; i++)
			if (x % i == 0) return 0;
		return 1;
	};

	int id = 1;
	while (!isprime(deg / 2)) {
		deg += 2;
		answer.push_back(vector<int> {id, id + n / 2});
		id += 1;
	}
	assert(id <= n);
	printf("%d\n", (int)answer.size());
	for (auto e : answer) {
		printf("%d %d\n", e[0], e[1]);
	}
}