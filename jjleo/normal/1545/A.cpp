#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[maxn], b[maxn], sum[maxn];
vector<int> v[maxn];

inline void add(int x, int y){
	for(;x < maxn;x += x & -x) b[x] += y;
}

inline int query(int x){
	int ans = 0;
	for(;x;x -= x & -x) ans += b[x];
	return ans;
}

int sk[maxn], top;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), sum[i] = 0;
		for(int i = 1;i <= n;i++) sum[i] += query(maxn - 1) - query(a[i]), add(a[i], 1);
		for(int i = 1;i <= n;i++) add(a[i], -1);
		for(int i = n;i;i--) sum[i] += query(a[i] - 1), add(a[i], 1);
		for(int i = 1;i <= n;i++) add(a[i], -1);
		for(int i = 1;i <= n;i++) v[a[i]].push_back(sum[i] & 1);
		bool tag = false;
		for(int i = 1;i <= n;i++){
			top = 0;
			for(int j = 0;j < v[a[i]].size();j++){
				if(top && sk[top] == v[a[i]][j]) top--;
				else sk[++top] = v[a[i]][j];
			}
			for(int j = 1;j <= top;j++){
				if(sk[j]){
					tag = true;
					break;
				}
			}
			if(tag) break;
			v[a[i]].clear();
		}
		for(int i = 1;i <= n;i++) v[a[i]].clear();
		puts(tag ? "NO" : "YES");
	}
}