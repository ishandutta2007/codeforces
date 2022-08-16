#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

// An implementation of segtree 
// from implicit segment tree, 
// using O(k * logN) memory, where 
// k is the number of insertions
const int N = 1e5 + 10, logN = 17;
// M = max overall memory
const int M = 5e6;
int lft[M], rgt[M], tree[M], cnt = 0;
struct segtree{
    int root;
    segtree(){root = ++cnt;}
    void insert(int rt, int val, int s, int e, int i){
        if(i < s || i > e) return;
        tree[rt] = max(tree[rt], val);
        if(s == e) return;
        int mid = (s + e) >> 1;
        if(i <= mid){       
            if(!lft[rt]) lft[rt] = ++cnt;
            insert(lft[rt], val, s, mid, i);
            return;
        }
        if(!rgt[rt]) rgt[rt] = ++cnt;
        insert(rgt[rt], val, mid + 1, e, i);
    }

    void insert(int x, int v){
        insert(root, v, 0, N - 1, x);
    }

    int get(int rt, int s, int e, int l, int r){
        if(!rt) return 0;
        if(l > e || s > r) return 0;
        if(s >= l && e <= r) return tree[rt];
        int mid = (s + e) >> 1;
        return max(get(lft[rt], s, mid, l, r), get(rgt[rt], mid + 1, e, l, r));
    }
    // maximum in <= x
    int get(int x){
        int ret =  get(root, 0, N - 1, 1, x);
        return ret;
    }
};

segtree st[N];

int main(){
	int n, m;
	sd(n); sd(m);
	int ans = 0;
	for(int i = 1; i <= m; i++){
		int a, b, w;
		sd(a); sd(b); sd(w); w++;
		int v = st[a].get(w - 1) + 1;
		ans = max(ans, v);
		st[b].insert(w, v);
	}
	printf("%d\n", ans);
}