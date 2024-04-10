#include <bits/stdc++.h>

using namespace std;

vector<vector<bool>> paper;
vector<vector<int>> adj;
int taken[200001], low[200001], tt[200001], isArt[200001];

int t = 0;

int DFS(int n, int p) { // returns low[n];
	t++;
	tt[n] = t;
	taken[n] = true;
	int c = 0;
	for(int i = 0; i < adj[n].size(); i++) {
		if(adj[n][i] == p) continue;
		if(taken[adj[n][i]]) {
			low[n] = min(low[n], tt[adj[n][i]]);
		}
		else {
			c++;
			int d = DFS(adj[n][i], n);
			if(p != -1) {
				if(d >= tt[n]) isArt[n] = true;
			}
			low[n] = min(low[n], d);
		}
	}
	if(p == -1) {
		if(c > 1) isArt[n] = true;
	}
	return low[n];
}

int main() {
	int r, c;
	cin >> r >> c;
	paper.resize(r+2);
	adj.resize(r*c);
	paper[0].resize(c+2);
	paper[r+1].resize(c+2);
	int sqs = 0;
	for(int i = 0; i < r; i++) {
		paper[i+1].resize(c+2);
		string s;
		cin >> s;
		for(int j = 0; j < c; j++) {
			if(s.at(j) == '#') {
				paper[i+1][j+1] = true;
				sqs++;
			}
		}
	}
	for(int i = 1; i <= r; i++) {
		for(int j = 1; j <= c; j++) {
			if(paper[i][j] && paper[i+1][j]) {
				adj[c*(i-1)+(j-1)].push_back(c*i+(j-1));
				adj[c*i+(j-1)].push_back(c*(i-1)+(j-1));
			}
			if(paper[i][j] && paper[i][j+1]) {
				adj[c*(i-1)+(j-1)].push_back(c*(i-1)+j);
				adj[c*(i-1)+j].push_back(c*(i-1)+(j-1));
			}
		}
	}
	for(int i = 0; i < r*c; i++) low[i] = 999999;
	for(int i = 0; i < r*c; i++) {
		if(taken[i]) continue;
		DFS(i, -1);
	}
	bool sad = false;
	for(int i = 0; i < r*c; i++) {
		sad |= isArt[i];
	}
	if(sqs <= 2) cout << "-1\n";
	else if(sad) cout << "1\n";
	else cout << "2\n";
}