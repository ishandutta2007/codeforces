#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <string>

using namespace std;

struct list{
	int next;
	int before;
};

int main() {
	int n, m, p;
	cin >> n >> m >> p;
	vector<char> arr(n);
	vector<char> deleted(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	stack<int> q;
	vector<int> pos(n);
	vector<list> l(n);
	for (int i = 1; i < n - 1; i++) {
		l[i].next = i + 1;
		l[i].before = i - 1;
	}
	l[n - 1].before = n - 2;
	l[n - 1].next = n - 1;
	l[0].before = 0;
	l[0].next = 1;
	for (int i = 0; i < n; i++) {
		if (arr[i] == '(') { q.push(i); }
		else {
			int c = q.top();
			q.pop();
			pos[c] = i;
			pos[i] = c;
		}
	}
	p--;
	for (int i = 0; i < m; i++) {
		char r;
		cin >> r;
		if (r == 'L') { p = l[p].before; }
		else {
			if (r == 'R') { p = l[p].next; }
			else {
				deleted[p] = 1;
				deleted[pos[p]] = 1;
				if (p > pos[p]) {
					if (l[p].next == p) {
						p = l[pos[p]].before;
						l[p].next = p;
					}
					else {
						if (l[pos[p]].before == pos[p]) {
							p = l[p].next;
							l[p].before = p;
						}
						else {
							l[l[p].next].before = l[pos[p]].before;
							l[l[pos[p]].before].next = l[p].next;
							p = l[p].next;
						}
					}
				}
				else {
					if (l[pos[p]].next == pos[p]) {
						p = l[p].before;
						l[p].next = p;
					}
					else {
						if (l[p].before == p) {
							p = l[pos[p]].next;
							l[p].before = p;
						}
						else {
							l[l[pos[p]].next].before = l[p].before;
							l[l[p].before].next = l[pos[p]].next;
							p = l[pos[p]].next;
						}
					}
				}
			}
		}
	}
				
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (res == 0 && !deleted[i]) { cout << arr[i]; }
		if (deleted[i]) {
			if (i < pos[i]) { res++; }
			else { res--; }
		}
	}

	return 0;
}