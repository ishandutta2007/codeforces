#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

struct Node{
	int sum, tag;
}t[maxn << 2];

int n, k;
int x;
vector<int> v;
int a[maxn];
int ans;

void cal(int l, int r){
	vector<int> v(r - l, 2e9);
	v[0] = -2e9;
	int sum = 0;
	for(int i = l + 1;i <= r - 1;i++){
		if(1ll * a[i] - a[l] - 1 < i - l - 1 || 1ll * a[r] - a[i] - 1 < r - i - 1) continue;
		int x = upper_bound(v.begin(), v.end(), a[i] - i) - v.begin();
		v[x] = a[i] - i;//  
		sum = max(sum, x);
	}
	//printf("%d %d %d--\n", l, r, sum);
	ans += r - l - 1 - sum; 
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	v.push_back(0), a[0] = -2e9;
	while(k--){
		scanf("%d", &x);
		v.push_back(x);
	} 
	v.push_back(n + 1), a[n + 1] = 2e9;
	for(int i = 1;i < v.size();i++){
		if(a[v[i]] <= a[v[i - 1]]) return printf("-1"), 0;
		if(1ll * a[v[i]] - a[v[i - 1]] - 1 < v[i] - v[i - 1] - 1) return printf("-1"), 0;
		cal(v[i - 1], v[i]);
	}
	printf("%d", ans);
}