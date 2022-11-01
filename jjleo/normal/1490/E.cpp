#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
pair<long long, int> a[maxn]; 
vector<int> ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%lld", &a[i].first), a[i].second = i;
		sort(a + 1, a + 1 + n);
		ans.clear();
		int l = 1;
		long long sum = a[1].first;
		for(int i = 2;i <= n;i++){
			if(a[i].first > a[i - 1].first){
				if(sum >= a[i].first){
					for(int j = l;j < i;j++) ans.push_back(a[j].second);
				}else{
					ans.clear();
				}
				l = i;
			}
			sum += a[i].first;
		}
		for(int j = l;j <= n;j++) ans.push_back(a[j].second);
		printf("%d\n", ans.size());
		sort(ans.begin(), ans.end());
		for(int i = 0;i < ans.size();i++) printf("%d ", ans[i]);
		puts("");
	}
}