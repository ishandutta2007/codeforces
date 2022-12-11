#include <bits/stdc++.h>

#define sz(a) (int)(a).size()
#define pb push_back
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("wa");

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string a, b;
	cin >> a >> b;

	if (a == b) {
		cout << "-1\n";
	} else {
		cout << max(sz(a), sz(b)) << "\n";
	}

}