#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

const int p = 998244353;

int t, n, s;
int a[maxn], b[maxn], x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &s);
		for(int i = 1;i <= n;i++) scanf("%d", &x), a[i] = x, b[i] = 0;
		int ans = 1;
		vector<int> v, w;
		for(int i = 1;i <= n;i++){
			scanf("%d", &x);
			if(x == -1) w.push_back(max(1, a[i] - s));
			else{
				b[x] = 1;
				if(x + s < a[i]) ans = 0;
			}
		}
		if(ans == 0){
			puts("0");
			continue;
		}
		for(int i = 1;i <= n;i++) if(!b[i]) v.push_back(i);
		sort(v.begin(), v.end());
		sort(w.begin(), w.end());
		int pos = (int)v.size() - 1, cnt = 0;
		for(int i = (int)w.size() - 1;i >= 0;i--){
			while(pos >= 0 && v[pos] >= w[i]) cnt++, pos--;
			ans = 1ll * ans * cnt % p;
			cnt--;
			if(ans == 0) break;
		}
		printf("%d\n", ans);
	}
}