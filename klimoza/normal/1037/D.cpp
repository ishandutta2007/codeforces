#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <deque>

using namespace std;



int main() {
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	int t1, t2;
	for (int i = 0; i < n - 1; i++) {
		cin >> t1 >> t2;
		t1--;
		t2--;
		g[t1].push_back(t2);
		g[t2].push_back(t1); 
	}
	queue<int> q;
	q.push(0);
	vector<bool> used(n);
	vector<int> d(n), p(n);
	vector<int> times(n);
	vector<int> child(n);
	used[0] = true;
	p[0] = -1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (size_t i = 0; i<g[v].size(); ++i) {
			int to = g[v][i];
			if (!used[to]) {
				used[to] = true;
				q.push(to);
				d[to] = d[v] + 1;
				times[d[to]]++;
				p[to] = v;
				child[v]++;
			}
		}
	}
	int t;
	cin >> t;
	if (t != 1) {
		cout << "No\n";
	}
	else if (n == 1) {
		cout << "Yes\n";
	}
	else {
		bool fl = true;
		int last;
		cin >> last;
		last--;
		times[d[last]]--;
		child[p[last]]--;
		deque<int> r;
		r.push_back(0);
		r.push_back(last);
		for (int i = 2; i < n; i++) {
			while(r.size() > 0 && child[r.front()] == 0) {
				r.pop_front();
			}
			cin >> t;
			t--;
			if (p[t] != r.front()) {
				fl = false;
				break;
			}
			if (d[t] < d[last]) {
				fl = false;
				break;
			}
			if (d[t] != d[last]) {
				if (times[d[last]] != 0) {
					fl = false;
					break;
				}
			}
			if (p[t] != p[last]) {
				if (child[p[last]] != 0) {
					fl = false;
					break;
				}
			}
			times[d[t]]--;
			child[p[t]]--;
			last = t;
			r.push_back(last);
		}
		if (fl) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}
	//system("pause");
	return 0;
}