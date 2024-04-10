#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 100;

#define magic_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>

int n, m, u, v, dis[MAXN], seq[MAXN], dc[MAXN], o[MAXN], p[MAXN];
vector<int> g[MAXN], d;
queue<int> q;
bool visited[MAXN];

int main(){
	magic_io;
	cin >> n;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		g[v].pb(u);
		g[u].pb(v);
	}
	q.push(1);
	visited[1] = 1;
	while(!q.empty()){
		v = q.front();
		q.pop();
		for(int i = 0; i < g[v].size(); i++){
			u = g[v][i];
			if(!visited[u]){
				visited[u] = 1;
				q.push(u);
				dis[u] = dis[v] + 1;
				p[u] = v;
			}
		}
	}
	for(int i = 0; i < n; i++){
		cin >> seq[i];
	}
	//cout << " #O# ";
	for(int i = 1; i < n; i++){
		if(dis[seq[i]] < dis[seq[i - 1]]){
			cout << "No";
			return 0;
		}
		o[seq[i]] = dc[dis[seq[i]]]++;
		if(dis[seq[i]] != dis[seq[i - 1]]){
			d.pb(i);
		}
		//cout << seq[i] << "_" << o[seq[i]] << ' ';
	}
	//cout << endl;
	d.pb(n);
	/*cout << " #D# ";
	for(int i = 0; i < d.size() - 1; i++){
		cout << d[i] << '_' << d[i + 1] << ' ';
	}
	cout << endl;*/
	for(int i = 0; i < d.size() - 1; i++){
		for(int j = d[i] + 1; j < d[i + 1]; j++){
			if(o[p[seq[j]]] < o[p[seq[j - 1]]]){
				cout << "No";
				return 0;
			}
		}
	}
	cout << "Yes";
	return 0;
}