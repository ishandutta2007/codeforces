#include<bits/stdc++.h>
#define REP(i, a, b) for(int i(a); i <= (b); ++i)

template <class T> inline bool smin(T&x, const T&y){return y < x ? x = y, 1 : 0;}
template <class T> inline bool smax(T&x, const T&y){return x < y ? x = y, 1 : 0;}

typedef long long ll;
const int N(5005);
int n, m, head[N], tot, bel[N], dfn[N], ind[N], pc;
struct Node{
	int u, v, w, ne;
}e[5000005];
inline void add(int x, int y, int z){
	e[++tot] = {x, y, z, head[x]}; head[x] = tot;
}
int dfs(int x){
	static int s[N], cnt;
	static bool ins[N];
	int low = dfn[x] = ++cnt;
	s[++s[0]] = x, ins[x] = 1;
	#define y e[i].v
	for(int i = head[x]; i; i = e[i].ne)
		if(!dfn[y])smin(low, dfs(y));
		else if(ins[y])smin(low, dfn[y]);
	#undef y
	if(low == dfn[x]){
		++pc;
		do ins[s[s[0]]] = 0, bel[s[s[0]]] = pc;
		while(s[s[0]--] != x);
	}
	return low;
}

int main(){
	scanf("%d%d", &n, &m);
	REP(i, 1, n){
		static char s[N];
		scanf("%s", s + 1);
		REP(j, 1, m)switch(s[j]){
			case '>' : add(n + j, i, 1); break;
			case '<' : add(i, n + j, 1); break;
			case '=' : add(i, n + j, 0), add(n + j, i, 0); break;
		}
	}
	REP(i, 1, n + m)if(!dfn[i])dfs(i);
	int pt = tot; tot = 0;
	memset(head, 0, sizeof head);
	REP(i, 1, pt){
		const int x = e[i].u, y = e[i].v;
		if(bel[x] && bel[x] == bel[y] && e[i].w)return puts("No"), 0;
		if(bel[x] != bel[y])
		add(bel[x], bel[y], e[i].w), ++ind[bel[y]];
	}
	
	static int d[N], q[N], l = 1, r;
	REP(i, 1, pc){
		d[i] = 1;
		if(!ind[i])q[++r] = i;	
	}
	while(l <= r){
		const int&x = q[l++];
		#define y e[i].v
		for(int i = head[x]; i; i = e[i].ne){
			smax(d[y], d[x] + e[i].w);
			if(!--ind[y])q[++r] = y;
		}
	}
	puts("Yes");
	REP(i, 1, n)printf("%d%c", d[bel[i]], " \n"[i == n]);
	REP(i, 1, m)printf("%d%c", d[bel[i + n]], " \n"[i == m]);
	return 0;
}