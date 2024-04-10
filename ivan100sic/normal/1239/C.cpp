#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

/*
pa da vam jebem majku mogli ste da se potrudite bar
malo da objasnite zadatak u pizdu materinu
*/

ll n, p;
ll t[100005];

struct event {
	ll t;
	int what;

	bool operator< (const event& b) const {
		return tie(t, what) < tie(b.t, b.what);
	}
};

ll ans[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> p;

	multiset<event> mse;
	for (int i=1; i<=n; i++) {
		cin >> t[i];
		mse.insert({t[i], i});
	}

	set<int> willing;
	queue<int> q;
	set<int> setq;
	int user = 0;

	auto gs = [&]() {
		if (setq.size() == 0)
			return 123123123;
		return *setq.begin();
	};

	while (mse.size()) {
		auto [t, what] = *mse.begin();
		mse.erase(mse.begin());

		if (what == 123123123) {
			ans[user] = t;
			setq.erase(user);
			user = 0;
		} else {
			willing.insert(what);
		}

		if (willing.size() && *willing.begin() < gs()) {
			int i = *willing.begin();
			willing.erase(i);
			setq.insert(i);
			q.push(i);
		}

		if (user == 0 && q.size()) {
			user = q.front();
			q.pop();
			mse.insert({t+p, 123123123});
		}
	}

	for (int i=1; i<=n; i++)
		cout << ans[i] << " \n"[i == n];
}