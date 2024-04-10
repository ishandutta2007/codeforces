#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

typedef long long ll;

int n, q;
char s[maxn];
int opt, l, r;
int fa[maxn], cnt = 1;
int son[maxn], id[maxn], pos[maxn], ed[maxn];
vector<ll> a, b[maxn];

inline void add(vector<ll> &a, int x, ll y){
	for(;x < a.size();x += x & -x) a[x] += y;
}

inline ll query(vector<ll> &a, int x){
	ll sum = 0;
	for(;x;x -= x & -x) sum += a[x];
	return sum;
}

bool tag[maxn];
vector<int> v;

int main(){
	scanf("%d%d%s", &n, &q, s + 1);
	for(int i = 1;i <= n;i++){
		if(s[i] == '(') v.push_back(i);
		else if(!v.empty()){
			tag[i] = tag[v.back()] = true;
			v.pop_back();
		}
	}
	int now = 1;
	for(int i = 1;i <= n;i++){
		if(!tag[i]) continue;
		if(s[i] == '('){
			son[now]++;
			fa[++cnt] = now, pos[cnt] = son[now];
			id[i] = now = cnt;
		}else{
			id[i] = now, ed[now] = cnt;
			now = fa[now];
		}
	}
	a.resize(n + 1);
	for(int i = 1;i <= cnt;i++){
		add(a, i, 1ll * son[i] * (son[i] + 1) / 2);
		b[i].resize(son[i] + 1); 
	}
	while(q--){
		scanf("%d%d%d", &opt, &l, &r);
		if(opt == 1){
			int x = id[l];
			add(a, fa[x], -(son[fa[x]]--));
			add(b[fa[x]], pos[x], -1);
		}else{
			l = id[l], r = id[r];
			ll ans = query(a, ed[r]) - query(a, l - 1);
			int x = pos[r] + query(b[fa[r]], pos[r]) - (pos[l] + query(b[fa[l]], pos[l])) + 1;
			printf("%lld\n", ans + 1ll * x * (x + 1) / 2);
		}
	}
}
/*
10 1
((((()))))
2 1 10
*/