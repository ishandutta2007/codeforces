#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		vector<int> v;
		long long ans = 0;
		for(int i = 1;i <= n;i++){
			int x, y;
			scanf("%d%d", &x, &y);
			if(x > y) swap(x, y);
			ans += x * 2;
			ans += y * 2;
			v.push_back(y);
		}
		sort(v.begin(), v.end());
		for(int i = 0;i + 1 < v.size();i++) ans -= 2 * v[i];
		printf("%lld\n", ans);
	}
}