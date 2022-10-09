#include <bits/stdc++.h>
using namespace std;

int k, n, m, a;
int g[105];

int votes[105], last[105];
int votes_b[105], last_b[105];

int calc_iznad(int i) {
	int iznad = 0;
	for (int j=1; j<=n; j++) {
		if (i != j) {
			if (votes[j] > votes[i] || (votes[j] == votes[i] && last[j] < last[i])) {
				iznad++;
			}
		}
	}
	return iznad;
}

void backup() {
	copy(votes, votes+105, votes_b);
	copy(last, last+105, last_b);
}

void restore() {
	copy(votes_b, votes_b+105, votes);
	copy(last_b, last_b+105, last);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> m >> a;
	for (int i=1; i<=a; i++) {
		cin >> g[i];
		votes[g[i]]++;
		last[g[i]] = i;
	}

	if (a == m) {
		// proverimo direktno
		for (int i=1; i<=n; i++) {
			int iznad = calc_iznad(i);

			if (iznad >= k || votes[i] == 0) {
				cout << "3 ";
			} else {
				cout << "1 ";
			}
		}
		return 0;
	}

	// sad se zezamo
	for (int i=1; i<=n; i++) {
		// sta ako svi glasaju za mene
		backup();

		// 3?
		votes[i] += m-a;
		last[i] = m;

		int iznad = calc_iznad(i);
		if (iznad >= k) {
			cout << "3 ";

			restore();
			continue;
		}

		restore();
		backup();

		// svi koji glasaju posle glasaju za kandidate koji imaju manje
		// glasova od mene, ili imaju jednako a last im je los
		int resto = m - a;
		int tm = a;

		vector<int> aktivni;
		for (int j=1; j<=n; j++) {
			if (i != j) {
				aktivni.push_back(j);
			}
		}

		sort(aktivni.begin(), aktivni.end(), [&](int a, int b) {
			return votes[a] > votes[b];
		});

		for (int j : aktivni) {
			if (votes[j] < votes[i]) {
				while (votes[j] <= votes[i] && resto) {
					resto--;
					votes[j]++;
					last[j] = ++tm;
				}
			} else if (votes[j] == votes[i] && last[j] > last[i] && resto) {
				resto--;
				votes[j]++;
				last[j] = ++tm;
			} else {
				// nista
			}
		}

		iznad = calc_iznad(i);

		if (iznad < k && votes[i] > 0) {
			cout << "1 ";
		} else {
			cout << "2 ";
		}

		restore();
	}
		
}