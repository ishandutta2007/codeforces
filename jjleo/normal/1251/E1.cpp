#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int t, n;
vector<int> v[maxn];
ll ans;
int x, y;
int cnt, sum;

priority_queue<int, vector<int>, greater<int> > q;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0;i < n;i++) v[i].clear();
		for(int i = 1;i <= n;i++){
			scanf("%d%d", &x, &y);
			v[x].push_back(y);
		}
		ans = cnt = 0, sum = n;
		while(!q.empty()) q.pop();
		for(int i = n - 1;i >= 0;i--){
			for(int j = 0;j < v[i].size();j++) q.push(v[i][j]);
			sum -= v[i].size();
			while(cnt + sum < i){
				ans += q.top();
				q.pop();
				++cnt;
			}
		}
		printf("%lld\n", ans);
	}
}