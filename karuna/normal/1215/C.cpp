#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int N;
vector<int> v1, v2;
vector<pii> ans;
string s, t;
int main() {
	cin >> N >> s >> t;

	for (int i=1; i<=N; i++) {
		if (s[i-1] == 'a' && t[i-1] == 'b') v1.push_back(i);
		if (s[i-1] == 'b' && t[i-1] == 'a') v2.push_back(i);
	}

	if ((v1.size() + v2.size())%2 != 0) {
		cout << -1; return 0;
	}

	for (int i=0; i+1<v1.size(); i+=2) {
		ans.emplace_back(v1[i], v1[i+1]);
	}

	for (int i=0; i+1<v2.size(); i+=2) {
		ans.emplace_back(v2[i], v2[i+1]);
	}

	if ((v1.size()&1) && (v2.size()&1)) {
		ans.emplace_back(v1.back(), v1.back());
		ans.emplace_back(v1.back(), v2.back());
	}

	cout << ans.size() << '\n';
	for (auto x : ans) {
		cout << x.va << ' ' << x.vb << '\n';
	}
}