#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, m;
vector<int> a[20];
int c, x;
set<vector<int> > st;
vector<pair<int, vector<int> > > v, w;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", &c);
		a[i].resize(c);
		for(int j = 0;j < c;j++) scanf("%d", &a[i][j]); 
	}
	scanf("%d", &m);
	for(int i = 1;i <= m;i++){
		vector<int> v(n);
		for(int j = 0;j < n;j++) scanf("%d", &v[j]);
		st.insert(v);
	}
	v.push_back({0, vector<int>(n)});
	for(int i = 1;i <= n;i++){
		int l = 1, r = 1e9, mid;
		while(l < r){
			mid = (l + r >> 1) + 1;
			long long sum = 0;
			for(int j = 0;j < v.size();j++) sum += a[i].end() - lower_bound(a[i].begin(), a[i].end(), mid - v[j].first);
			if(sum >= m + 1) l = mid;
			else r = mid - 1;
		}
		for(int j = 0;j < v.size();j++){
			for(int k = a[i].size() - 1;k >= 0 && v[j].first + a[i][k] >= l;k--){
				w.push_back(v[j]);
				w.back().first += a[i][k], w.back().second[i - 1] = k + 1;
			}
		}
		swap(v, w), w.clear();
		//printf("l:%d | ", l);
		//for(int j = 0;j < v.size();j++) printf("%d ", v[j].first);puts("--"); 
	}
	sort(v.begin(), v.end());
	//printf("%d--\n", v.size());
	for(int i = v.size() - 1;i >= 0;i--){
		if(st.find(v[i].second) == st.end()){
			for(int j = 0;j < v[i].second.size();j++) printf("%d ", v[i].second[j]);
			return 0;
		}
	}
}