#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

const int p = 998244353;

int t, n;
int x, y;
vector<int> v[maxn];
int Gcd, k;
bool tag[maxn], flag;

int dfs(int i, int fa){
	if(flag) return 0;
	int val = 0;
	for(int j = 0;j < v[i].size();j++){
		int to = v[i][j];
		if(to == fa) continue;
		int sum = dfs(to, i);
		if(sum % k == 0) val++;
		else if((sum + 1) % k == 0) sum++;
		else{
			flag = true;
			break;
		}
		Gcd = __gcd(Gcd, sum);
	}
	return val;
}

void solve(int i){
	Gcd = flag = 0, k = i;
	int val = dfs(1, 0);
	if(!flag && val % k == 0) tag[__gcd(Gcd, val)] = true;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) v[i].clear(), tag[i] = false;
		for(int i = 1;i < n;i++){
			scanf("%d%d", &x, &y);
			v[x].push_back(y), v[y].push_back(x);
		}
		int ans = 1;for(int i = 1;i < n;i++) ans = (ans + ans) % p;
		int x = n - 1;
		for(int i = 2;i * i < n && x > 1;i++){
			if(x % i) continue;
			while(x % i == 0) x /= i;
			solve(i);
		}
		if(x > 1) solve(x);
		for(int i = 2;i < n;i++) ans = (ans + p - tag[i]) % p;
		printf("%d ", ans);
		for(int i = 2;i <= n;i++) printf("%d ", tag[i]);puts("");
	}
}