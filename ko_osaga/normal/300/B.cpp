#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;

bool vis[100];
vector<vector<int>> s;
vector<int> gph[555];
int n,m;

vector<int> aux;
void dfs(int x){
	if(vis[x]) return;
	vis[x] = 1;
	aux.push_back(x+1);
	for(auto &i : gph[x]){
		dfs(i);
	}
}

int main(){
	cin >> n >> m;
	for(int i=0; i<m; i++){
		int s, e; cin >> s >> e; s--, e--;gph[s].push_back(e); gph[e].push_back(s);

	}
	for(int i=0; i<n; i++){
		if(!vis[i]){
			dfs(i);
			s.push_back(aux);
			if(aux.size() > 3){
				puts("-1");
				return 0;
			}
			aux.clear();
		}
	}
	sort(s.begin(), s.end(), [&](const vector<int> &a, const vector<int> &b){
			return a.size() < b.size();
			});
	int c1 = 0, c2 = 0;
	for(auto &i : s){
		if(i.size() == 1) c1++;
		if(i.size() == 2) c2++;
	}
	if(c1 < c2){
		puts("-1");
		return 0;
	}
	for(int i=0; i<c1-c2; i+=3){
		printf("%d %d %d\n", s[i][0], s[i+1][0], s[i+2][0]);
	}
	for(int i=0; i<c2; i++){
		printf("%d %d %d\n", s[c1-c2+i][0], s[c1+i][0], s[c1+i][1]);
	}
	for(int i=0; i<s.size(); i++){
		if(s[i].size() == 3){
			for(auto &j : s[i]) printf("%d ", j);
			puts("");
		}
	}

}