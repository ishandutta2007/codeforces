#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

const int sup = 1e5;

int n, x;
bool vis[maxn];
long long ans;
int cnt[maxn];
int mu[maxn], prm[maxn], f[maxn], tot;
bool tag[maxn];

int sk[maxn], top;
vector<int> v[maxn];

inline void push(int x){
	sk[++top] = x;
	for(int i = 0;i < v[x].size();i++) cnt[v[x][i]]++;
}

inline int pop(){
	int x = sk[top--];
	for(int i = 0;i < v[x].size();i++) cnt[v[x][i]]--;
	return x;
}

int main(){
	mu[1] = 1;
	for(int i = 2;i <= sup;i++){
		if(!tag[i]) prm[++tot] = i, mu[i] = -1;
		for(int j = 1;j <= tot && prm[j] * i <= sup;j++){
			tag[i * prm[j]] = true;
			if(i % prm[j] == 0) break;
			mu[i * prm[j]] = -mu[i];
		}
	}
	for(int i = 1;i <= sup;i++){
		for(int j = 1;j * i <= sup;j++){
			v[j * i].push_back(i);
		}
	}
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		if(vis[x]) ans = max(ans, 1ll * x);
		vis[x] = true;
	} 
	for(int i = 1;i <= sup;i++){
		while(top) pop();//debug: 
		for(int j = sup / i;j;j--){
			if(!vis[i * j]) continue;
			int x = 0;
			for(int k = 0;k < v[j].size();k++) x += mu[v[j][k]] * cnt[v[j][k]];
			while(x){
				int y = pop();
				if(__gcd(j, y) == 1) x--, ans = max(ans, 1ll * j * y * i);//debug:gcdi 
			}
			push(j);
		}
	}
	printf("%lld", ans);
}