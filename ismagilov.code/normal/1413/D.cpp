#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define dump(a) #a << " = " << (a)

typedef long long ll;
typedef long double ld;
using namespace std;

const ll INF = 1e9;
const ll MOD = 228228227;

struct Event {
	char type;
	int x, event_id, sale_id, good_id;
	Event (char type, int x, int event_id, int sale_id): type(type), x(x), event_id(event_id), sale_id(sale_id) {};
	Event (char type, int event_id, int good_id): type(type), event_id(event_id), good_id(good_id) {};
};

inline void solve() {
	int n;
	cin >> n;

	vector <Event> events;

	char type;
	int x, sale_id = 0, good_id = 0;
	for (int i = 0; i < 2 * n; i++) {
		cin >> type;

		if (type == '+') {
			events.push_back(Event('+', i, good_id));
			good_id++;
		} else if (type == '-') {
			cin >> x;
			events.push_back(Event('-', x, i, sale_id));
			sale_id++;
		}
	}

	vector <int> offsets(n, -1), sales(n);
	for (auto &event: events) {
		if (event.type == '+') continue;
		sales[event.sale_id] = event.x;
		offsets[event.sale_id] = event.sale_id - 1;

		while (offsets[event.sale_id] > -1 && sales[event.sale_id] > sales[offsets[event.sale_id]]) {
			offsets[event.sale_id] = offsets[offsets[event.sale_id]];
		}
	}


	int prev_sale = -1;
	vector <int> answer(n);
	set <pair <int, int>> goods;

	for (auto &event: events) {
		if (event.type == '-') {
			if (goods.empty()) {
				cout << "NO\n";
				return;
			}

			auto it = goods.lower_bound({offsets[event.sale_id], -INF});
			if (it == goods.end()) {
				cout << "NO\n";
				return;
			}

            auto mmm = (*it).second;
			goods.erase(it);
			answer[mmm] = event.x;
			prev_sale = event.sale_id;
		} else if (event.type == '+') {
			goods.insert({prev_sale, event.good_id});
		}
	}

	cout << "YES\n";
	for (int i = 0; i < n; i++)
		cout << answer[i] << ' ';
	cout << '\n';
}

signed main() {
	srand((unsigned int)time(NULL));
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	solve();
}