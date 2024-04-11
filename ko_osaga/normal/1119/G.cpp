#include <bits/stdc++.h>
using namespace std;
using pi = pair<int, int>;
const int MAXN = 1000005;
const int mod = 1e9 + 7;
using lint = long long;

int n, m, a[MAXN];
vector<int> ans[MAXN];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0; i<m; i++){
		scanf("%d",&a[i]);
	}
	int cur = 0;
	vector<int> v;
	for(int i=0; i<m; i++){
		cur += a[i];
		if(i + 1 < m)v.push_back(cur % n);
	}
	v.push_back(n);
	v.push_back(0);
	int itr = (cur + n - 1) / n;
	printf("%d\n", itr);
	sort(v.begin(), v.end());
	for(int i=1; i<=m; i++) printf("%d ", v[i] - v[i-1]);
	puts("");
	cur = 0;
	for(int i=0; i<m; i++){
		while(a[i] > 0){
			cur++;
			if(cur == m + 1) cur = 1;
			a[i] -= v[cur] - v[cur - 1];
			ans[cur].push_back(i + 1);
		}
	}
	for(int i=0; i<itr; i++){
		for(int j=1; j<=m; j++){
			if(ans[j].size() <= i) printf("1 ");
			else printf("%d ", ans[j][i]);
		}
		puts("");
	}
}