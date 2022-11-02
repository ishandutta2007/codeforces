#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, greater<int> > q;
vector<int> v[100009];
bool vs[100009];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b); v[b].push_back(a);
	}
	q.push(1); vs[1] = true; 
	for (int i = 1; i <= n; i++) {
		int hn = q.top(); q.pop();
		cout << hn << " ";
		for (int j = 0; j < v[hn].size(); j++) {
			int tn = v[hn][j];
			if (!vs[tn]) {
				q.push(tn); vs[tn] = true;
			}
		}
	}
	cout << '\n';
	return 0;
}