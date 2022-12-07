#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, m;
vector<int> v, w[maxn];
int a[maxn], A[maxn];
int b[maxn], c[305][305];
int l[maxn], r[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		v.clear();
		for(int i = 1;i <= n * m;i++) scanf("%d", &a[i]), A[i] = a[i], v.push_back(a[i]);
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		int k = v.size();
		for(int i = 1;i <= k;i++) l[i] = 1e9, r[i] = 0, w[i].clear();
		sort(a + 1, a + 1 + n * m);
		for(int i = 1;i <= n * m;i++){
			a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
			l[a[i]] = min(l[a[i]], i), r[a[i]] = max(r[a[i]], i);
		}
		for(int i = 1;i <= k;i++){
			if((l[i] - 1) / m == (r[i] - 1) / m){
				for(int j = r[i];j >= l[i];j--) w[i].push_back(j);
			}else{
				for(int j = (l[i] - 1) / m * m + m;j >= l[i];j--) w[i].push_back(j);
				for(int j = (l[i] - 1) / m + 1;j < (r[i] - 1) / m;j++){
					for(int jj = m;jj >= 1;jj--) w[i].push_back(j * m + jj);
				}
				for(int j = r[i];j >= (r[i] - 1) / m * m + 1;j--) w[i].push_back(j);
			}
			reverse(w[i].begin(), w[i].end());
		}
		int ans = 0;
		for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) c[i][j] = 0;
		for(int i = 1;i <= n * m;i++){
			int x = lower_bound(v.begin(), v.end(), A[i]) - v.begin() + 1;
			int I = (w[x].back() - 1) / m + 1, pos = w[x].back() % m;
			//printf("%d %d--\n", x, w[x].back());
			w[x].pop_back();
			if(pos == 0) pos = m;
			for(int j = 1;j <= pos;j++) ans += c[I][j];
			c[I][pos] = 1;
		}
		printf("%d\n", ans); 
	}
}