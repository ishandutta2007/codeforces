#include <bits/stdc++.h>
#define maxn 105

using namespace std;

int n, k;
int c[maxn * maxn];
vector<int> v[maxn];
vector<pair<int, int> > a;
bool vis[maxn];
int l[maxn], r[maxn];

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n * k;i++){
		scanf("%d", &c[i]);
		v[c[i]].push_back(i);
	}
	int cnt = (n + k - 2) / (k - 1), sum = n;
	for(int i = 0;i < k - 1;i++){
		a.clear();
		for(int j = 1;j <= n;j++) if(!vis[j]) a.push_back({v[j][i + 1], v[j][i]});
		sort(a.begin(), a.end());
		int tot = min(cnt, sum);
		sum -= tot;
		for(int j = 0;j < tot;j++){
			l[c[a[j].first]] = a[j].second;
			r[c[a[j].first]] = a[j].first;
			vis[c[a[j].first]] = true;
		}
	}
	for(int i = 1;i <= n;i++) printf("%d %d\n", l[i], r[i]);
}