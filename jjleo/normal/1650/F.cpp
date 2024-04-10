#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, m;
int a[maxn];
vector<tuple<int, int, int> > v[maxn];
int f[maxn][200], g[maxn][200];

void solve(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]), v[i].clear();
	for(int i = 1;i <= m;i++){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		v[x].push_back(make_tuple(y, z, i));
	}
	int t = 0;
	for(int k = 1;k < 200;k++) f[0][k] = 1e9 + 1;
	vector<int> ans;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j < v[i].size();j++){
			for(int k = 0;k < 200;k++){
				f[j + 1][k] = f[j][k];
				g[j + 1][k] = 0;
				int siz = get<1>(v[i][j]), val = get<0>(v[i][j]);
				if(k - siz >= 0 && f[j][k - siz] + val < f[j + 1][k]) f[j + 1][k] = f[j][k - siz] + val, g[j + 1][k] = 1;
			}
		}
		int pos = 100;
		for(int j = 101;j < 200;j++) if(f[v[i].size()][j] < f[v[i].size()][pos]) pos = j;
		if(t + f[v[i].size()][pos] > a[i]){
			puts("-1");
			return;
		}
		t += f[v[i].size()][pos];
		vector<int> w;
		for(int j = (int)v[i].size() - 1;~j;j--){
			if(g[j + 1][pos]){
				w.push_back(get<2>(v[i][j]));
				pos -= get<1>(v[i][j]);
			}
		}
		reverse(w.begin(), w.end());
		ans.insert(ans.end(), w.begin(), w.end());
	}
	printf("%d\n", ans.size());
	for(int i = 0;i < ans.size();i++) printf("%d ", ans[i]);puts("");
}

int main(){
	scanf("%d", &t);
	while(t--) solve();
}