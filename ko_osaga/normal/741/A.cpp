#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long lint;

int n, a[105];
int vis[105];
int indeg[105], outdeg[105];

int dfs(int x){
	if(vis[x]) return 0;
	vis[x] = 1;
	return 1 + dfs(a[x]);
}

lint gcd(lint x, lint y){
	return y ? gcd(y, x%y) : x;
}

lint lcm(lint x, lint y){
	return x * (y / gcd(x, y));
}

int main(){
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		indeg[i]++;
		outdeg[a[i]]++;
	}
	for(int i=1; i<=n; i++){
		if(indeg[i] != 1 || outdeg[i] != 1){
			puts("-1");
			return 0;
		}
	}
	lint ret = 1;
	for(int i=1; i<=n; i++){
		if(vis[i]) continue;
		int w = dfs(i);
		if(w%2 == 0) w /= 2;
		ret = lcm(ret, w);
	}
	cout << ret;
}