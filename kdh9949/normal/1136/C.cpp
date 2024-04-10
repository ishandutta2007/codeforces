#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m;
vector<int> v[N], w[N];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
		int x; scanf("%d", &x);
		v[i + j].push_back(x);
	}
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
		int x; scanf("%d", &x);
		w[i + j].push_back(x);
	}
	for(int i = 0; i < n + m - 1; i++){
		sort(v[i].begin(), v[i].end());
		sort(w[i].begin(), w[i].end());
		if(v[i] != w[i]){ puts("NO"); return 0; }
	}
	puts("YES");
}