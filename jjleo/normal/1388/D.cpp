#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int n;
ll a[maxn], b[maxn];
int deg[maxn];
ll ans;
queue<int> q;
vector<int> v, c;
bool tag[maxn];


int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
	for(int i = 1;i <= n;i++) scanf("%lld", &b[i]);
	for(int i = 1;i <= n;i++){
		if(b[i] == -1) continue;
		deg[b[i]]++;
	}
	for(int i = 1;i <= n;i++) if(!deg[i]) q.push(i);
	while(!q.empty()){
		int x = q.front();q.pop();
		v.push_back(x);
		if(b[x] != -1){
			deg[b[x]]--;
			if(deg[b[x]] == 0) q.push(b[x]);
		}
	}
	for(int i = 0;i < n;i++){
		if(a[v[i]] > 0 && !tag[v[i]]){
			ans += a[v[i]];
			tag[v[i]] = true;
			if(b[v[i]] != -1) a[b[v[i]]] += a[v[i]];
			c.push_back(v[i]);
		}
	}
	for(int i = n - 1;~i;i--){
		if(!tag[v[i]]){
			ans += a[v[i]];
			tag[v[i]] = true;
			if(b[v[i]] != -1) a[b[v[i]]] += a[v[i]];
			c.push_back(v[i]);
		}
	}
	printf("%lld\n", ans);
	for(int i = 0;i < n;i++) printf("%d ", c[i]);
}