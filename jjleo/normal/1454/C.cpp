#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
int a[maxn];
vector<int> v[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) v[i].clear();
		int x = 1;
		for(int i = 1;i <= n;i++){
			scanf("%d", &a[i]);
			v[a[i]].push_back(i);
		}
		int ans = n;
		for(int i = 1;i <= n;i++){
			if(v[i].empty()) continue;
			if(v[i].size() == n){
				ans = 0;
				break;
			}
			int sum = 0;
			for(int j = 0;j < v[i].size();j++){
				if(j == 0 || v[i][j] != v[i][j - 1] + 1) sum++;
			}
			sum++;
			if(v[i][0] == 1) sum--;
			if(v[i].back() == n) sum--;
			ans = min(ans, sum);
		}
		printf("%d\n", ans);
	}
}