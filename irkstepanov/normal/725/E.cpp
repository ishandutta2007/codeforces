#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

const int nmax = 200500;

int main()
{

	//ifstream cin("input.txt");

	int c;
	cin >> c;

	vector<int> cnt(nmax);
	int n;
	cin >> n;

	while (n--) {
		int x;
		cin >> x;
		++cnt[x];
	}

	vector<int> first(nmax);
	first[0] = -1;
	for (int i = 1; i < nmax; ++i) {
		first[i] = first[i - 1];
		if (cnt[i]) {
			first[i] = i;
		}
	}

	for (int d = 0; d < c; ++d) {
		int curr = c;
		int pos = first[curr];
		while (pos >= d) {
			int num = min(curr / pos, cnt[pos]);
			curr -= num * pos;
			pos = min(first[pos - 1], first[curr]);
		}
		if (curr >= d) {
			curr -= d;
		}
		while (pos != -1) {
			int num = min(curr / pos, cnt[pos]);
			curr -= num * pos;
			pos = min(first[pos - 1], first[curr]);
		}
		if (curr) {
			cout << d << "\n";
			return 0;
		}
	}

	cout << "Greed is good\n";

}