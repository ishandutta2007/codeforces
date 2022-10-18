#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fs first
#define sc second
#define endl "\n"
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int n; //  
	int s, kek;	
	cin >> n;
	vector<int> g[n];
	for (int i = 0; i < n; i++){
		cin >> kek;
		kek--;
		g[i].push_back(kek);
	} 
	for (int i = 0; i < n; i++){
		if (i == 0){
			g[i].push_back(i+1);
		}
		else
		if (i == n-1){
			g[i].push_back(i-1);
		}
		else{
			g[i].push_back(i-1);
			g[i].push_back(i+1);
		}
	}
	s = 0;
	queue<int> q;
	q.push (s);
	vector<bool> used (n);
	vector<int> d (n), p (n);
	used[s] = true;
	p[s] = -1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (size_t i=0; i<g[v].size(); ++i) {
			int to = g[v][i];
			if (!used[to]) {
				used[to] = true;
				q.push (to);
				d[to] = d[v] + 1;
				p[to] = v;
			}
		}
	}
	for (int i = 0; i < n; i++){
		cout << d[i] << ' ';
	}
}