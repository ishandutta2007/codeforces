#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n, m, k;
int a[maxn], mx[maxn]; 
int x, y;
vector<int> v[maxn];
bool tag[maxn], t;

queue<int> q;
int dis1[maxn], dis2[maxn];
multiset<int> st1, st2;
int ans;

inline bool cmp(int x, int y){
	return dis1[x] < dis1[y];
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1;i <= k;i++) scanf("%d", &a[i]), tag[a[i]] = true;
	while(m--){
		scanf("%d%d", &x, &y);
		v[x].push_back(y), v[y].push_back(x);
		if(tag[x] && tag[y]) t = true;
	}
	q.push(1);
	while(!q.empty()){
		x = q.front();q.pop();
		for(int i = 0;i < v[x].size();i++){
			y = v[x][i];
			if(dis1[y] || y == 1) continue;
			dis1[y] = dis1[x] + 1;
			q.push(y);
		}
	}
	if(t) return printf("%d", dis1[n]), 0;
	q.push(n);
	while(!q.empty()){
		x = q.front();q.pop();
		for(int i = 0;i < v[x].size();i++){
			y = v[x][i];
			if(dis2[y] || y == n) continue;
			dis2[y] = dis2[x] + 1;
			q.push(y);
		}
	}
	sort(a + 1, a + 1 + k, cmp);
	for(int i = k;i;i--) mx[i] = max(mx[i - 1], dis2[a[i]]);
	for(int i = 1;i < k;i++) ans = max(ans, dis1[a[i]] + mx[i + 1] + 1); 
	printf("%d", min(dis1[n], ans));
}