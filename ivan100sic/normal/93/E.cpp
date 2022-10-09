// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll n;
int k;
int a[105];

ll brut(ll p, int i) {
	if (i == k || a[i] > p)
		return p;
	return brut(p, i+1) - brut(p / a[i], i+1);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> k;
	for (int i=0; i<k; i++)
		cin >> a[i];

	if (count(a, a+k, 1)) {
		cout << "0\n";
		return 0;

	}

	sort(a, a+k, greater<int>());
	// cout << rek(n, 0) << '\n';

	vector<pair<ll, int>> vec = {{n, 1}};
	for (int i=0; i<k; i++) {
		vector<pair<ll, int>> tmp, mrg;
		for (auto [p, v] : vec) {
			if (p >= a[i]) {
				ll p2 = p / a[i];
				tmp.emplace_back(p2, -v);
			}
		}

		int j = 0;
		for (auto [p, v] : vec) {
			while (j < (int)tmp.size() && tmp[j].first <= p)
				mrg.push_back(tmp[j++]);
			if (mrg.size() && mrg.back().first == p)
				mrg.back().second += v;
			else
				mrg.emplace_back(p, v);
		}

		swap(vec, mrg);
	}

	ll sol = 0;
	for (auto [p, v] : vec)
		sol += p * v;
	cout << sol << '\n';
}

/*
10000000000000 100
2  3  5  7  11  13  17  19  23  29  31  37  41  43  47  53  59  61
 67  71  73  79  83  89  97  101  103  107  109  113  127  131  137
  139  149  151  157  163  167  173  179  181  191  193  197  199
	211  223  227  229  233  239  241  251  257  263  269  271  277
	281  283  293  307  311  313  317  331  337  347  349  353  359
	367  373  379  383  389  397  401  409  419  421  431  433  439
	443  449  457  461  463  467  479  487  491  499  503  509  521
	523  541

*/