#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	a--; b--;
	if (s[a] == s[b]) cout << 0 << endl;
	else cout << 1 << endl;
}