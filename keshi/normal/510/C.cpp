#include <bits/stdc++.h>
using namespace std;

#define fast_io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int n;
string a, b;
bool visited[26], dor;
vector<int> ans, g[26], h[26];

bool child(int v, int u){
	bool c = 0;
	int w;
	visited[v] = 1;
	for(int i = 0; i < g[v].size(); i++){
		w = g[v][i];
		if(w == u){
			return 1;
		}
		if(!visited[w]){
			if(child(w, u)){
				return 1;
			}
		}
	}
	return 0;
}

void adj(){
	for(int i = 0; i < min(a.size(), b.size()); i++){
		if(a[i] != b[i]){
			fill(visited, visited + 26, 0);
			if(child(b[i] - 'a', a[i] - 'a')){
				dor = 1;
			}
			fill(visited, visited + 26, 0);
			if(!child(a[i] - 'a', b[i] - 'a')){
				g[a[i] - 'a'].push_back(b[i] - 'a');
				h[b[i] - 'a'].push_back(a[i] - 'a');
			}
			return;
		}
	}
	if(a.size() > b.size()){
		dor = 1;
	}
	return;
}


void dfs(int v){
	int u;
	ans.push_back(v);
	visited[v] = 1;
	for(int i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!visited[u]){
			dfs(u);
		}
	}
	return;
}

int main(){
	int v, u, j;
	fast_io;
	cin >> n;
	cin >> a;
	for(int i = 1; i < n; i++){
		cin >> b;
		adj();
		a = b;
	}
	if(dor){
		cout << "Impossible";
	}
	else{
		fill(visited, visited + 26, 0);
		for(int i = 0; i < 26; i++){
			j = i;
			while(h[j].size()){
				if(h[j].size() == 1){
					j = h[j][0];
					continue;
				}
				v = h[j][0];
				u = h[j][1];
				
				fill(visited, visited + 26, 0);
				
				//cout << " # " << char(j + 'a') << ' ' <<  char(v + 'a') << ' ' << char(u + 'a') << endl;
				if(child(v, u)){
					h[j].erase(find(h[j].begin(), h[j].end(), v));
					g[v].erase(find(g[v].begin(), g[v].end(), j));
				}
				else{
					h[j].erase(find(h[j].begin(), h[j].end(), u));
					g[u].erase(find(g[u].begin(), g[u].end(), j));
					if(!child(u, v)){
						g[u].push_back(v);
						h[v].push_back(u);
					}
					/*cout << "  #" <<  char('a' + u) << "# ";
					for(int i = 0; i < g[u].size(); i++){
						cout << char('a' + g[u][i]) << ' ';
					}
					cout << endl;
					
					cout << "  #" <<  char('a' + v) << "# ";
					for(int i = 0; i < h[v].size(); i++){
						cout << char('a' + h[v][i]) << ' ';
					}
					cout << endl;
					fill(visited, visited + 26, 0);
					ans.clear();
					dfs(u);
					cout << " => ";
					for(int i = 0; i < ans.size(); i++){
						cout << char('a' + ans[i]);
					}
					ans.clear();
					cout << endl;*/
				}
			}
		}
		fill(visited, visited + 26, 0);
		ans.clear();
		for(int i = 0; i < 26; i++){
			if(h[i].size() == 0 && !visited[i]){
				dfs(i);
			}
		}
		for(int i = 0; i < 26; i++){
			cout << char('a' + ans[i]);
		}
	}
	return 0;
}