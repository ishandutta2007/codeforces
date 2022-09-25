#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

#define sqr(x) ((x)*(x))

int n,w1[5000],w2[5000],vert,d[5000];
vector <int> e[5000];
bool vis[5000];
deque <int> q;

bool dfs(int v,int x) {
	vis[v]=true;
	for (int i=0; i<e[v].size(); i++) {
		if (e[v][i]!=x && vis[e[v][i]]) {
			vert=e[v][i];
			q.push_back(v);
			return true;
		}
		if (!vis[e[v][i]] && dfs(e[v][i],v)){
			if (v!=vert) {
				q.push_back(v);
				return true;
			}
			else {
				q.push_back(v); 
				return false;
			}
		}
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);	
	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> w1[i] >> w2[i];
		e[w1[i]-1].push_back(w2[i]-1);
		e[w2[i]-1].push_back(w1[i]-1);
	}
	for (int i=0; i<n; i++) sort(e[i].begin(), e[i].end());
	dfs(0,0);
	for (int i=0; i<n; i++) vis[i]=false;
	for (deque <int> :: iterator it=q.begin(); it!=q.end(); it++) {
		vis[*it]=true;
		d[*it]=0;
	}

	while (!q.empty()) {
		int v=q.front();
		for (int i=0; i<e[v].size(); i++) {
			if (!vis[e[v][i]]) {
				d[e[v][i]]=d[v]+1;
				q.push_back(e[v][i]);
				vis[e[v][i]]=true;
			}
		}
		q.pop_front();
	}
	for (int i=0; i<n; i++) {
		cout << d[i]<< ' ';
	}
	return 0;
}