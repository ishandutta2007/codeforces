#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n, m; 
map<int, vector<int> > mp;
int a[maxn];
int R[maxn];
int b[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		mp.clear();
		for(int i = 1;i <= n;i++){
			scanf("%d", &a[i]);
			mp[a[i]].push_back(i);
			R[i] = 0;
		}
		for(int i = 1;i <= m;i++){
			int l, r;
			scanf("%d%d", &l, &r);
			R[l] = max(R[l], r);
		}
		int mn = n, mx = 0, ans = n;
		int r = 0;
		for(int i = 1;i <= n;i++){
			r = max(r, R[i]);
			vector<int> &v = mp[a[i]];
			int p = lower_bound(v.begin(), v.end(), i) - v.begin();
			if(p + 1 < v.size() && v[p + 1] <= r) mn = min(mn, v[p + 1]);
			if(r >= i){
				p = upper_bound(v.begin(), v.end(), r) - v.begin() - 1;
				b[i] = v[p];
				if(p > 0) mx = max(mx, v[p - 1]);
			}else b[i] = 0;
		}
		if(mx == 0){
			puts("0");
			continue;
		}
		for(int i = 1;i <= mn;i++){
			ans = min(ans, mx - i + 1);
			mx = max(mx, b[i]);
		}
		printf("%d\n", max(ans, 0));
	}
}