#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
map<int, bool> mp;
int x;
int ans;
priority_queue<int> q;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		mp.clear();
		ans = 0;
		while(n--){
			scanf("%d", &x);
			if(x & 1) continue;
			if(mp[x]) continue;
			mp[x] = true;
			q.push(x);
		}
		while(!q.empty()){
			x = q.top();q.pop();
			ans++;
			x >>= 1;
			if(mp[x] || (x & 1)) continue;
			mp[x] = true;
			q.push(x);
		}
		printf("%d\n", ans);
	}
}