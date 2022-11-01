#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

int n;
vector<int> v[maxn];
int a[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		int l, x;
		scanf("%d", &l);
		while(l--) scanf("%d", &x), v[i].push_back(x);
	}
	long long ans = 1ll * n * n;
	for(int i = 1;i <= n;i++){
		bool tag = false;
		for(int j = 0;j + 1 < v[i].size();j++) if(v[i][j] < v[i][j + 1]) tag = true;
		if(!tag) a[v[i].back()]++;
	}
	for(int i = maxn - 2;~i;i--) a[i] += a[i + 1];
	for(int i = 1;i <= n;i++){
		bool tag = false;
		for(int j = 0;j + 1 < v[i].size();j++) if(v[i][j] < v[i][j + 1]) tag = true;
		if(!tag) ans -= a[v[i][0]];
	}
	printf("%lld", ans);
}