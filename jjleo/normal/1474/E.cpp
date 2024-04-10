#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[maxn];
vector<pair<int, int> > v;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n), v.clear();
		for(int i = 1;i <= n;i++) a[i] = i;
		long long ans = 1ll * (n - 1) * (n - 1);
		v.push_back({1, n}), swap(a[1], a[n]);
		int l = 2, r = n - 1;
		while(l <= r){
			if(l == r){
				v.push_back({l, 1}), swap(a[1], a[l]);
				ans += 1ll * (l - 1) * (l - 1); 
			}else{
				v.push_back({r, 1}), v.push_back({l, n});
				swap(a[1], a[r]), swap(a[l], a[n]);
				ans += 2ll * (r - 1) * (r - 1); 
			}
			l++, r--;
		}
		printf("%lld\n", ans);
		for(int i = 1;i <= n;i++) printf("%d ", a[i]);
		printf("\n%d\n", n - 1);
		for(int i = v.size() - 1;~i;i--) printf("%d %d\n", v[i].first, v[i].second); 
	}
}