#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int, int>
#define ll long long
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string a, b;
bool f, s;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> a >> b;
	if (a.size() != b.size())
		return cout << "No\n", 0;
	for (int i = 0; i < a.size(); i++) {
		f = (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o'
				|| a[i] == 'u');
		s = (b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o'
				|| b[i] == 'u');
		if (f != s)
			return cout << "No\n", 0;
	}
	return cout << "Yes\n", 0;
}