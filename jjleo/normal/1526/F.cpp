#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, a, b, ans[maxn];

inline int query(int i, int j, int k){
	int x;
	printf("? %d %d %d\n", i, j, k), fflush(stdout);
	scanf("%d", &x);
	return x;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		bool tag = false;
		for(int i = 1;i <= min(n, 13) && !tag;i++) for(int j = 1;j < i && !tag;j++) for(int k = 1;k < j && !tag;k++){
			if(query(i, j, k) <= max(1, (n - 4) / 6)) tag = true, a = i, b = j;
		}
		int mx = 0, sx = 0;
		vector<int> v, w;
		for(int i = 1;i <= n;i++){
			if(i == a || i == b) continue;
			int x = query(i, a, b);
			if(x > mx) swap(mx, sx), mx = x, swap(v, w), v.clear(), v.push_back(i);
			else if(x == mx) v.push_back(i);
			else if(x > sx) sx = x, w.clear(), w.push_back(i);
			else if(x == sx) w.push_back(i);
		}
		b = v.back();
		int mn = n, id;
		for(int i = 0;i < w.size();i++){
			int x = query(w[i], a, b);
			if(x < mn) mn = x, id = w[i];
		}
		a = id;
		ans[b] = 1, ans[a] = 2;
		for(int i = 1;i <= n;i++){
			if(i == a || i == b) continue;
			ans[i] = query(i, a, b) + 2;
		}
		if(ans[1] > ans[2]) for(int i = 1;i <= n;i++) ans[i] = n - ans[i] + 1;
		printf("!");for(int i = 1;i <= n;i++) printf(" %d", ans[i]);puts(""), fflush(stdout);
		scanf("%d", &a);
	}
}