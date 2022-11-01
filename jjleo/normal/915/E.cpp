#include <bits/stdc++.h>

using namespace std;

struct Node{
	int l, r, v;
	Node(int L, int R = -1, int V = 0){
		l = L, r = R, v = V;
	}
};

inline bool operator < (Node x, Node y){
	return x.l < y.l; 
} 

set<Node> st;

#define IT set<Node>::iterator

inline IT split(int pos){
	IT it = st.lower_bound(Node(pos));
	if(it != st.end() && it->l == pos) return it;
	--it;
	int l = it->l, r = it->r, v = it->v;
	st.erase(it);
	st.insert(Node(l, pos - 1, v));
	return st.insert(Node(pos, r, v)).first;
}

inline void assign(int l, int r, int v){
	IT itr = split(r + 1), itl = split(l);
	st.erase(itl, itr);
	st.insert(Node(l, r, v));
}

int n, q;
int l, r, v;
int ans;

int main(){
	scanf("%d%d", &n, &q);
	st.insert(Node(1, n, 2));
	ans = n;
	while(q--){
		scanf("%d%d%d", &l, &r, &v);
		IT itr = split(r + 1), itl = split(l);
		for(;itl != itr;++itl){
			if(itl->v == 1 && v == 2) ans += itl->r - itl->l + 1;
			else if(itl->v == 2 && v == 1) ans -= itl->r - itl->l + 1;
		}
		printf("%d\n", ans);
		assign(l, r, v);
	}
}