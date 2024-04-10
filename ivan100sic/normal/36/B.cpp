#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

vector<string> farbaj(vector<string> baza, vector<string> model) {
	int n = baza.size();
	int k = model.size();
	vector<string> rez(n*k, string(n*k, 0));

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			if (baza[i][j] == '.') {
				for (int u=0; u<k; u++)
					for (int v=0; v<k; v++)
						rez[k*i+u][k*j+v] = model[u][v];
			} else {
				for (int u=0; u<k; u++)
					for (int v=0; v<k; v++)
						rez[k*i+u][k*j+v] = '*';
			}
		}
	}

	return rez;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	#ifdef LOCAL
		auto& input = cin;
		auto& output = cout;
	#else
		ifstream input("input.txt");
		ofstream output("output.txt");
	#endif

	int k, t;
	input >> k >> t;

	vector<string> model(k);
	for (int i=0; i<k; i++) {
		input >> model[i];
	}

	vector<string> f = {"."};
	while (t--) {
		f = farbaj(f, model);
	}
	for (auto s : f)
		output << s << '\n';
}