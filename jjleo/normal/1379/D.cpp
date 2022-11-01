#include <bits/stdc++.h>
#define maxn 800086

using namespace std;

int n, h, m, k;
int a[maxn], x, y;
vector<pair<int, int> > v;
int b[maxn], n0;
int f[maxn];
int mn, id;
vector<int> ans;

int main(){
	scanf("%d%d%d%d", &n, &h, &m, &k), m /= 2;
	/*if(k == m){
		printf("%d %d\n", n, 0);
		for(int i = 1;i <= n;i++) printf("%d ", i);
		return 0;
	}*/
	if(k <= 2) return printf("%d %d\n", 0, 0), 0;
	for(int i = 1;i <= n;i++){
		scanf("%d%d", &x, &y), a[i] = y = (y + 1) % m;
		if(y + k - 1 > m) v.push_back({y, m}), v.push_back({0, y + k - 1 - m});
		else v.push_back({y, y + k - 1});
	}
	for(int i = 0;i < v.size();i++){
		b[++n0] = v[i].first, b[++n0] = v[i].second;
		//printf("%d %d--\n", v[i].first, v[i].second + 1);
	}
	b[++n0] = 0, b[++n0] = m;
	sort(b + 1, b + 1 + n0);
	n0 = unique(b + 1, b + 1 + n0) - (b + 1);
	//for(int i = 1;i <= n0;i++) printf("%d--\n", b[i]);
	for(int i = 0;i < v.size();i++){
		int l = lower_bound(b + 1, b + 1 + n0, v[i].first) - b;
		int r = lower_bound(b + 1, b + 1 + n0, v[i].second) - b;
		//printf("%d %d--\n", l, r);
		f[l]++, f[r]--;
	}
	mn = n, id = 1;
	for(int i = 1;i < n0;i++){
		f[i] += f[i - 1];
		//printf("%d %d--\n", b[i], f[i]);
		if(f[i] < mn) mn = f[i], id = i;
	}
	int l = b[id], r = b[id + 1] - 1;
	for(int i = 1;i <= n;i++){
		if(a[i] + k - 2 >= m){
			if(!(a[i] > r || l > m - 1)){
				ans.push_back(i);
			}else if(!(0 > r || l > a[i] + k - 2 - m)){
				ans.push_back(i);
			}
		}else{
			if(!(a[i] > r || l > a[i] + k - 2)){
				ans.push_back(i);
			}
		}
	}
	printf("%d %d\n", mn, b[id]);
	for(int i = 0;i < ans.size();i++) printf("%d ", ans[i]);
	
}