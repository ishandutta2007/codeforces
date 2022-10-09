#include <bits/stdc++.h>
using namespace std;

string f0 = R"(What are you doing at the end of the world? Are you busy? Will you save us?)";

string sl = R"(What are you doing while sending ")";
string sm = R"("? Are you busy? Will you send ")";
string sr = R"("?)";

long long xl = sl.size();
long long xm = sm.size();
long long xr = sr.size();

long long vel[100005];

char solve(int n, long long k) {
	if (k >= vel[n]) {
		return '.';
	}

	if (n == 0) {
		return f0[k];
	}

	if (k < xl) {
		return sl[k];
	}
	k -= xl;

	if (k < vel[n-1]) {
		return solve(n-1, k);
	}
	k -= vel[n-1];

	if (k < xm) {
		return sm[k];
	}
	k -= xm;

	if (k < vel[n-1]) {
		return solve(n-1, k);
	}
	k -= vel[n-1];

	return sr[k];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	vel[0] = f0.size();
	for (int i=1; i<=100000; i++) {
		long long sc = xl + xm + xr + 2 * vel[i-1];
		vel[i] = min(sc, 2'000'000'000'000'000'000ll);
	}

	int q;
	cin >> q;
	string sol;
	while (q--) {
		int n;
		long long k;
		cin >> n >> k;
		k--;

		sol += solve(n, k);
	}
	cout << sol << '\n';
}