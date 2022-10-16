#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	using i64 = int64_t;
	i64 K; cin >> K;
	const string S = "codeforces";
	for (int l = int(S.size()); true; l++) {
		i64 v = 1;
		string T;
		for (int i = 0; i < int(S.size()); i++) {
			i64 cnt = l / int(S.size()) + (i < (l % int(S.size())));
			for (int z = 0; z < cnt; z++) T += S[i];
			v *= cnt;
		}
		if (v >= K) {
			cout << T << '\n';
			break;
		}
	}

	return 0;
}