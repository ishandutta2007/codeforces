
#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");

	int n;
	cin >> n;

	string s;
	cin >> s;
	
	int curr = 0;
	for (int i = 0; i <= n; ++i) {
		if (i == n || s[i] == '0') {
			cout << curr;
			curr = 0;
			continue;
		}
		++curr;
	}
	cout << "\n";
		
}