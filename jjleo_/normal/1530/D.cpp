#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
int a[maxn], id[maxn];
bool in[maxn], out[maxn];
vector<int> v, w;
int to[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) id[i] = in[i] = out[i] = 0;
		int ans = 0;
		for(int i = 1;i <= n;i++){
			scanf("%d", &a[i]);
			if(!id[a[i]]) id[a[i]] = i, to[i] = a[i], ans++, out[i] = true, in[a[i]] = true;
		}
		v.clear();
		for(int i = 1;i <= n;i++) if(!out[i] && !in[i]) v.push_back(i);
		if(v.size() == 1){
			to[id[a[v[0]]]] = v[0], to[v[0]] = a[v[0]], in[v[0]] = out[v[0]] = true;
		}else{
			for(int i = 0;i < v.size();i++) to[v[i]] = v[(i + 1) % v.size()], in[v[i]] = out[v[i]] = true;
		}
		v.clear(), w.clear();
		for(int i = 1;i <= n;i++){
			if(!in[i]) v.push_back(i);
			if(!out[i]) w.push_back(i);
		}
		for(int i = 0;i < v.size();i++) to[w[i]] = v[i];
		printf("%d\n", ans);
		for(int i = 1;i <= n;i++) printf("%d ", to[i]);puts("");
	}
}