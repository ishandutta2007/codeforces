#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int MAXN = 1005;

int n, m;
int a[MAXN][MAXN];
int lo[MAXN][MAXN];
int hi[MAXN][MAXN];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) scanf("%d",&a[i][j]);
	}
	for(int i=0; i<n; i++){
		vector<int> v(a[i], a[i] + m);
		sort(v.begin(), v.end());
		v.resize(unique(v.begin(), v.end()) - v.begin());
		for(int j=0; j<m; j++){
			int pos = lower_bound(v.begin(), v.end(), a[i][j]) - v.begin();
			lo[i][j] = max(lo[i][j], pos);
			hi[i][j] = max(hi[i][j], (int)v.size() - 1 - pos);
		}
	}
	for(int j=0; j<m; j++){
		vector<int> v;
		for(int i=0; i<n; i++) v.push_back(a[i][j]);
		sort(v.begin(), v.end());
		v.resize(unique(v.begin(), v.end()) - v.begin());
		for(int i=0; i<n; i++){
			int pos = lower_bound(v.begin(), v.end(), a[i][j]) - v.begin();
			lo[i][j] = max(lo[i][j], pos);
			hi[i][j] = max(hi[i][j], (int)v.size() - 1 - pos);
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			printf("%d ", lo[i][j] + hi[i][j] + 1);
		}
		puts("");
	}
}