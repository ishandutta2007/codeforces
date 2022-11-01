#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

struct SGT{
	struct Node{
		int son[2];
		bool sum;
	}t[maxn << 7];
	
	int cnt;
	int root[maxn << 1];
	
	#define ls(x) (t[x].son[0])
	#define rs(x) (t[x].son[1]) 

	void modify(int x, int l, int r, int pos){
		t[x].sum = true;
		if(l == r) return;
		int mid = l + r >> 1;
		if(mid >= pos) modify(ls(x) = ++cnt, l, mid, pos);
		else modify(rs(x) = ++cnt, mid + 1, r, pos); 
	}
	
	bool query(int x, int l, int r, int ll, int rr){
		if(!x) return false;
		if(ll <= l && r <= rr) return t[x].sum;
		int mid = l + r >> 1;
		bool sum = false;
		if(mid >= ll) sum |= query(ls(x), l, mid, ll, rr);
		if(mid < rr) sum |= query(rs(x), mid + 1, r, ll, rr);
		return sum;
	}
	
	int merge(int x, int y){//debug:  
		if(!x || !y) return x | y;
		int z = ++cnt;
		ls(z) = merge(ls(x), ls(y)), rs(z) = merge(rs(x), rs(y));
		t[z].sum = true;
		return z;
	}
}tree;

struct SAM{
	struct Node{//State 
		int len, link;//maxlen 
		int edge[26];
		int endpos;//endpos 
	}t[maxn << 1];
	
	int cnt, last;
	
	void init(){
		t[1].len = 0;
		t[1].link = 0;
		last = 1;
		cnt = 1;// 
	}
	
	void insert(char c){
		int x = c - 'a';
		int cur = ++cnt;
		t[cur].len = t[last].len + 1;//1i-1 1i len+1 
		int p = last;
		for(;p && !t[p].edge[x];p = t[p].link) t[p].edge[x] = cur;//1-i-1 
		if(!p){
			t[cur].link = 1;
		}else{
			int q = t[p].edge[x];
			if(t[q].len == t[p].len + 1){// S[1-j]  ji 
				t[cur].link = q;
			}else{// S[1-j]  S[1-j] edge link 
				int clone = ++cnt;
				t[clone].len = t[p].len + 1;
				memcpy(t[clone].edge, t[q].edge, sizeof(t[q].edge));
				for(;p && t[p].edge[x] == q;p = t[p].link) t[p].edge[x] = clone;//q pqpq
				t[clone].link = t[q].link;
				t[q].link = t[cur].link = clone;
			}
		}
		last = cur;
	}
}sam;

int len, ans;
char s[maxn], a;
int q, l, r;

int bk[maxn], sa[maxn << 1]; 

int f[maxn << 1];
int fa[maxn << 1];

int main(){
	scanf("%d%s", &len, s + 1);
	sam.init();
	for(int i = 1;i <= len;i++){
		sam.insert(s[i]);
		tree.modify(tree.root[sam.last] = ++tree.cnt, 1, len, i);
		sam.t[sam.last].endpos = i;
	}
	
	for(int i = 2;i <= sam.cnt;i++) bk[sam.t[i].len]++;
	for(int i = 2;i <= len;i++) bk[i] += bk[i - 1];
	for(int i = 2;i <= sam.cnt;i++) sa[bk[sam.t[i].len]--] = i;
	
	tree.root[1] = ++tree.cnt;
	for(int i = sam.cnt - 1;i;i--){
		tree.root[sam.t[sa[i]].link] = tree.merge(tree.root[sam.t[sa[i]].link], tree.root[sa[i]]);
		sam.t[sam.t[sa[i]].link].endpos = sam.t[sa[i]].endpos;
	}
	
	
	for(int i = 1;i < sam.cnt;i++){
		if(sam.t[sa[i]].link == 1) f[sa[i]] = 1, fa[sa[i]] = sa[i];
		else if(tree.query(tree.root[fa[sam.t[sa[i]].link]], 1, len, sam.t[sa[i]].endpos - sam.t[sa[i]].len + sam.t[fa[sam.t[sa[i]].link]].len, sam.t[sa[i]].endpos - 1)){
			f[sa[i]] = f[sam.t[sa[i]].link] + 1;
			fa[sa[i]] = sa[i];
		}else{
			f[sa[i]] = f[sam.t[sa[i]].link];
			fa[sa[i]] = fa[sam.t[sa[i]].link];
		}
		ans = max(ans, f[sa[i]]);
	}
	printf("%d", ans);
}