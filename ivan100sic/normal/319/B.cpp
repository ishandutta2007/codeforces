#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005];
list<int> idx;
vector<list<int>::iterator> proveri; 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		idx.push_back(i);
	}

	for (auto it = idx.begin(); it != idx.end(); ++it)
		proveri.push_back(it);

	int z = 0;

	while (1) {
		// proveri to sto ima da se proveri
		vector<list<int>::iterator> youdied, novi_proveri, tmp;
		set<int> mrtvi;
		bool nesto = 0;

		for (auto it : proveri) {
			if (it != idx.end() && next(it) != idx.end() && a[*it] > a[*next(it)]) {
				youdied.push_back(next(it));
				novi_proveri.push_back(it);
				nesto = 1;
			}
		}

		if (!nesto)
			break;
		else
			z++;

		for (auto it : youdied)
			mrtvi.insert(*it);

		for (auto it : novi_proveri)
			if (!mrtvi.count(*it))
				tmp.push_back(it);

		for (auto it : youdied)
			idx.erase(it);

		swap(proveri, tmp);
	}

	cout << z << '\n';
}