#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	int n;
	cin >> n;

	map<int, int> mapa;
	while (n--) {
		int x;
		cin >> x;
		++mapa[x];
	}

	int hi = -1;
	for (auto it : mapa) {
		hi = max(hi, it.second);
	}

	cout << hi << " " << sz(mapa) << "\n";

}