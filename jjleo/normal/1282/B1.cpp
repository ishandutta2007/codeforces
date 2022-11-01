#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n, p, k;
int a[maxn];
vector<int> v[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n, &p, &k);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		for(int i = 0;i < k;i++) v[i].clear();
		for(int i = k;i <= n;i++){
			v[i % k].push_back(a[i]);
			if(v[i % k].size() > 1) v[i % k][v[i % k].size() - 1] += v[i % k][v[i % k].size() - 2];
		}
		int ans = 0;
		for(int i = 0;i <= n;i++){
			p -= a[i];
			if(p < 0) break;
			int l = i / k, r = (int)v[i % k].size() - 1, mid;
			//printf("%d %d %d--\n", i, l, r);
			if(l > r){
				ans = max(ans, i);
				continue;
			}
			while(l < r){
				mid = (l + r >> 1) + 1;
				if(v[i % k][mid] <= p) l = mid;
				else r = mid - 1;
			}
			if(v[i % k][l] <= p) ans = max(ans, i + (l - i / k + 1) * k);
			else ans = max(ans, i);
		}
		/*for(int i = n;i;i--){
			if(i >= k){
				if(p >= a[i]) ans += k, p -= a[i], i -= k - 1;
			}else{
				for(int j = 1;j <= i;j++){
					if(p >= a[j]) ans++, p -= a[j];
					else break;
				}
				break;
			}
		}*/
		printf("%d\n", ans);
	}	
}