#include<bits/stdc++.h>
#define REP(i, a, b) for(int i(a); i <= (b); ++i)

#define gc getchar()
struct Reader{
	template <class T> inline operator T() {
		T w; char c, p = 0;
		for(; !isdigit(c = gc); c == '-' && (p = 1));
		for(w = c & 15; isdigit(c = gc); w = w * 10 + (c & 15));
		return p ? -w : w;
	}
}rd;

template <class T> inline bool smin(T&x, const T&y){return y < x ? x = y, 1 : 0;}
template <class T> inline bool smax(T&x, const T&y){return x < y ? x = y, 1 : 0;}

typedef long long ll;

const int N(150005);
struct Node{
	int ls, rs, fa, rnd;
}t[N];
inline int merge(int x, int y){
	if(!x || !y)return x | y;
	if(t[x].rnd < t[y].rnd)
	return t[x].rs = merge(t[x].rs, y), t[t[x].rs].fa = x;
	return t[y].ls = merge(x, t[y].ls), t[t[y].ls].fa = y;
}
void dfs(int x){
	if(!x)return;
	dfs(t[x].ls), printf("%d ", x), dfs(t[x].rs);
}
int main(){
	int n = rd;
	REP(i, 1, n)t[i].rnd = rand();
	while(--n){
		int x = rd, y = rd;
		while(t[x].fa)x = t[x].fa;
		while(t[y].fa)y = t[y].fa;
		merge(x, y);
	}
	int x = 1;
	while(t[x].fa)x = t[x].fa;
	dfs(x);
	return 0;
}