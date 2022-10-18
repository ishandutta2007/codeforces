#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

struct Query {
	int type, i, j = 0;
	vector<int> next;
	int result = 0;
};

vector<Query> queries;
int n, m;

struct Shelve {
	set<int> books;
	bool inverted;
};

void compResults(int cur, vector<Shelve> &shelves, int num) {
	auto &q = queries[cur];
	bool done = false;
	if (q.type == 1) {
		auto &sh = shelves[q.i];
		if (sh.inverted)
		{
			if (sh.books.count(q.j)) {
				sh.books.erase(q.j);
				done = true;
				num++;
			}
		}
		else {
			if (!sh.books.count(q.j)) {
				sh.books.insert(q.j);
				num++;
				done = true;
			}
		}
	}
	else if (q.type == 2) {
		auto &sh = shelves[q.i];
		if (!sh.inverted)
		{
			if (sh.books.count(q.j)) {
				sh.books.erase(q.j);
				done = true;
				num--;
			}
		}
		else {
			if (!sh.books.count(q.j)) {
				sh.books.insert(q.j);
				done = true;
				num--;
			}
		}
	}
	else if (q.type == 3) {
		done = true;
		auto &sh = shelves[q.i];
		if (sh.inverted) {
			int old_num = m - sh.books.size();
			int new_num = sh.books.size();
			num = num - old_num + new_num;
		}
		else {
			int old_num = sh.books.size();
			int new_num = m - sh.books.size();
			num = num - old_num + new_num;
		}
		sh.inverted = !sh.inverted;
	}

	queries[cur].result = num;

	for (auto next : q.next) {
		compResults(next, shelves, num);
	}


	if (!done)
		return;

	if (q.type == 1) {
		auto &sh = shelves[q.i];
		if (!sh.inverted)
		{
			sh.books.erase(q.j);
		}
		else {
			sh.books.insert(q.j);
		}
	}
	else if (q.type == 2) {
		auto &sh = shelves[q.i];
		if (sh.inverted)
		{
			sh.books.erase(q.j);
		}
		else {
			sh.books.insert(q.j);
		}
	}
	else if (q.type == 3) {
		auto &sh = shelves[q.i];
		sh.inverted = !sh.inverted;
	}
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie (NULL);
    cout.precision(10);
    cout << fixed;

	int Q;
	cin >> n >> m >> Q;

	queries = vector<Query>(Q + 1);
	queries[0].type = 4;

	for (int i = 1; i <= Q; i++) {
		int t;
		cin >> t;
		queries[i].type = t;
		cin >> queries[i].i;
		queries[i].i--;
		if (t < 3)
			cin >> queries[i].j;
		if (t < 4) {
			queries[i-1].next.push_back(i);
		}
		else {
			queries[queries[i].i + 1].next.push_back(i);
		}
	}

	vector<Shelve> shelves(n);
	for (auto i : shelves) {
		i.books.clear();
		i.inverted = false;
	}

	compResults(0, shelves, 0);

	for (int i = 1; i < Q + 1; i++)
		cout << queries[i].result << endl;
}