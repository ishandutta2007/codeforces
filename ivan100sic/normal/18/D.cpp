// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
basic_string<int> wins[12345];
int sell[12345], win[12345];
bool used[5005];

int pows[2001][1234];

int ans[1234];
int tmp[1234];

void reg(int* tmp) {
	for (int j=0; j<1233; j++) {
		tmp[j+1] += tmp[j] / 10;
		tmp[j] %= 10;
	}
}

void add(int i) {
	for (int j=0; j<1234; j++)
		ans[j] += pows[i][j];

	reg(ans);
}

void print() {
	for (int y=0, j=1233; j>=0; j--) {
		if (ans[j] || j == 0) {
			y = 1;
		}
		if (y)
			cout << ans[j];
	}
	cout << '\n';
}

void prec() {
	pows[0][0] = 1;
	for (int i=1; i<=2000; i++) {
		for (int j=0; j<1234; j++)
			pows[i][j] = pows[i-1][j] << 1;
		reg(pows[i]);
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	prec();

	cin >> n;
	for (int i=1; i<=n; i++) {
		string s;
		int x;
		cin >> s >> x;
		if (s == "win") {
			wins[x] += i;
		} else {
			sell[x] = i;
		}
	}

	for (int i=0; i<12345; i++) {
		for (int j=(int)wins[i].size()-1; j>=0; j--) {
			if (wins[i][j] < sell[i]) {
				win[i] = wins[i][j];
				break;
			}
		}
	}

	for (int i=12344; i>=0; i--) {
		if (win[i] && sell[i]) {
			bool ok = 1;
			for (int j=win[i]; j<=sell[i]; j++) {
				if (used[j]) {
					ok = 0;
				}
			}

			if (ok) {
				add(i);
				for (int j=win[i]; j<=sell[i]; j++) {
					used[j] = 1;
				}
			}
		}
	}

	print();
}