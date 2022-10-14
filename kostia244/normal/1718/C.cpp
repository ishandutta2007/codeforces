#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, Q; cin >> N >> Q;
		std::vector<int> A(N); for (auto& a : A) cin >> a;

		std::vector<std::vector<int64_t>> facs; facs.reserve(N);
		std::set<std::tuple<int64_t, int, int>> vals;
		for (int v = N, p = 2; v > 1; p++) {
			if (v % p == 0) {
				while (v % p == 0) v /= p;

				int k = N / p;
				facs.emplace_back(k);
				for (int i = 0; i < N; i++) {
					facs.back()[i%k] += A[i];
				}
				for (int i = 0; i < k; i++) {
					vals.insert({facs.back()[i] * k, k, i});
				}
			}
		}
		cout << std::get<0>(*std::prev(vals.end())) << '\n';
		for (int q = 0; q < Q; q++) {
			int p, x; cin >> p >> x; p--;
			x -= A[p];
			A[p] += x;
			for (auto& v : facs) {
				int k = int(v.size());
				vals.erase({v[p%k] * k, k, p % k});
				v[p%k] += x;
				vals.insert({v[p%k] * k, k, p % k});
			}
			cout << std::get<0>(*std::prev(vals.end())) << '\n';
		}
	}

	return 0;
}