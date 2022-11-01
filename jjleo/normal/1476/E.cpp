#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int n, m, k;
inline int id(string s){
	int sum = 0;
	for(int i = 0;i < s.length();i++){
		sum = sum * 27 + (s[i] == '_' ? 26 : s[i] - 'a');
	}
	return sum;
}
int a[maxn];
int x;
vector<int> v[maxn];
int deg[maxn];
queue<int> q; 
vector<int> ans;
string s;

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1;i <= n;i++){
		cin >> s;
		a[id(s)] = i;
	}
	for(int i = 1;i <= m;i++){
		string S;
		cin >> S;
		scanf("%d", &x);
		bool tag = false;
		for(int l = 0;l < (1 << k);l++){
			string s = S;
			for(int o = 0;o < k;o++){
				if(l & (1 << o)) s[o] = '_';
			}
			int y = id(s);
			if(a[y] == x){
				tag = true; 
				continue;
			}
			if(a[y]){
				v[x].push_back(a[y]);
				deg[a[y]]++;
				//printf("%d %d--\n", x, a[y]);
			}
		}
		if(!tag) return printf("NO"), 0;
	}
	for(int i = 1;i <= n;i++) if(!deg[i]) q.push(i);
	while(!q.empty()){
		int x = q.front();q.pop();
		ans.push_back(x);
		for(int i = 0;i < v[x].size();i++){
			int to = v[x][i];
			deg[to]--;
			if(!deg[to]) q.push(to);
		}
	}
	if(ans.size() < n) return printf("NO"), 0;
	puts("YES"); 
	for(int i = 0;i < ans.size();i++) printf("%d ", ans[i]);
}