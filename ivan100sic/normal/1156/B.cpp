#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T, class U>
void print_with_perm(T perm, U flist) {
	int k = flist.size();
	for (int i=0; i<k; i++) {
		int q = perm[i] - 1;
		cout << string(flist[q].second, flist[q].first);
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		map<char, int> freq;
		for (char x : s)
			freq[x]++;

		basic_string<pair<char, int>> flist(freq.begin(), freq.end());

		if (flist.size() > 3) {
			basic_string<int> perm;
			int k = flist.size();
			if (k % 2 == 0) {
				for (int i=k/2; i>=1; i--) {
					perm += i;
					perm += i + k/2;
				}
			} else {
				for (int i=k/2+1; i>=2; i--) {
					perm += i;
					perm += i + k/2;
				}
				perm += 1;
			}

			print_with_perm(perm, flist);
		} else if (flist.size() == 1) {
			cout << s << '\n';
		} else if (flist.size() == 2) {
			// moze samo ako nisu susedna ta dva slova
			if (flist[1].first - flist[0].first != 1) {
				cout << s << '\n';
			} else {
				cout << "No answer\n";
			}
		} else {
			int d1 = flist[1].first - flist[0].first;
			int d2 = flist[2].first - flist[1].first;

			if (d1 > 1) {
				print_with_perm(basic_string<int>{2, 1, 3}, flist);
			} else if (d2 > 1) {
				print_with_perm(basic_string<int>{2, 3, 1}, flist);
			} else {
				cout << "No answer\n";
			}
		}
	}
}