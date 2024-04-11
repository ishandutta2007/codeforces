#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vi vector<ll>
#define pi pair<int, int>
using namespace std;
//1 + 1 + 2 + 3 + 4 + 5 + 6 + 8
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll a, b, c = 0, d = 0, m, ans = 0;
list<int> l;
vi v;

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin >> m;
	v.resize(m);
	for(auto& i : v) cin >> i;
	sort(v.begin(), v.end());
	bool f = false;
	int p1 = 0, p2 = v.size() - 1;
	while(p1 <= p2) {
		if(f)
			l.push_front(v[p2]), p2--;
		else
			l.push_back(v[p2]), p2--;
		f = !f;
	}
	for(auto& i : l) cout << i << " ";
}