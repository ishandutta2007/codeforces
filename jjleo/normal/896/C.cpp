#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Node{
	int l, r;
	mutable ll v;
	Node(int L, int R = -1, ll V = 0){
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
	int l = it->l, r = it->r;
	ll v = it->v;
	st.erase(it);
	st.insert(Node(l, pos - 1, v));
	return st.insert(Node(pos, r, v)).first;
}

inline void assign(int l, int r, ll v){
	IT itl = split(l), itr = split(r + 1);
	st.erase(itl, itr);
	st.insert(Node(l, r, v));
}

int n, m, seed, vmax;

inline int rnd(){
	int ret = seed;
    seed = (1ll * seed * 7 + 13) % 1000000007;
    return ret;
}

vector<pair<ll, int> > v;

inline int fpow(int x, int y, int p){
	int ans = 1;
	while(y){
		if(y & 1) ans = 1ll * ans * x % p;
		x = 1ll * x * x % p, y >>= 1;
	}
	return ans;
}

int main(){
	scanf("%d%d%d%d", &n, &m, &seed, &vmax);
	for(int i = 1;i <= n;i++) st.insert(Node(i, i, rnd() % vmax + 1));
	st.insert(Node(n + 1, n + 1, 0)); 
	for(int i = 1;i <= m;i++){
		int op = rnd() % 4 + 1, l = rnd() % n + 1, r = rnd() % n + 1;
		if(l > r) swap(l, r);
		int x, y;
		if(op == 3){
			x = rnd() % (r - l + 1) + 1;
		}else{
			x = rnd() % vmax + 1;
		}
		if(op == 4){
			y = rnd() % vmax + 1;
		}
		IT itl, itr;
		//printf("%d %d %d %d--\n", op, l, r, x);
		switch(op){
			case 1:
				itl = split(l), itr = split(r + 1);
				for(;itl != itr;++itl){
					itl->v += x;
				}
				break;
			case 2:
				assign(l, r, x);
				break;	
			case 3:
				v.clear();
				itl = split(l), itr = split(r + 1);
				for(;itl != itr;++itl){
					v.push_back({itl->v, itl->r - itl->l + 1}); 
				} 
				sort(v.begin(), v.end());
				for(int i = 0;i < v.size();i++){
					x -= v[i].second;
					if(x <= 0){
						printf("%lld\n", v[i].first);
						break;
					}
				}
				break;	
			case 4:
				int ans = 0;
				itl = split(l), itr = split(r + 1);
				for(;itl != itr;++itl){
					ans = (ans + 1ll * (itl->r - itl->l + 1) * fpow(itl->v % y, x, y)) % y;
				}
				printf("%d\n", ans);
				break;
		}
	}
}