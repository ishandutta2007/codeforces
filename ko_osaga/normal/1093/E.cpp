#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 200005;
const int MAXT = 530000;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> drzewa;

struct bit{
	drzewa drz[MAXN];
	void add(int x, int v){
		while(x < MAXN){
			drz[x].insert(v);
			x += x & -x;
		}
	}
	void remove(int x, int v){
		while(x < MAXN){
			drz[x].erase(v);
			x += x & -x;
		}
	}
	int query(int l, int s, int e){
		int ret = 0;
		while(l){
			ret += 
			drz[l].order_of_key(e + 1) - 
			drz[l].order_of_key(s);
			l -= l & -l;
		}
		return ret;
	}
}bit;

int n, q;
int reva[MAXN], revb[MAXN], b[MAXN];
int A[MAXN];

int main(){
	scanf("%d %d",&n,&q);
	for(int i=0; i<n; i++){
		int x; scanf("%d",&x); reva[x] = i + 1;
	}
	for(int i=0; i<n; i++){
		int x; scanf("%d",&x); revb[x] = i + 1;
		b[i + 1] = x;
	}
	for(int i=1; i<=n; i++){
		A[reva[i]] = revb[i]; 
		bit.add(reva[i], A[reva[i]]);
	}
	while(q--){
		int t; scanf("%d",&t);
		if(t == 1){
			int l1, r1, l2, r2;
			scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
			int ret = bit.query(r1, l2, r2) - bit.query(l1-1, l2, r2);;
			printf("%d\n", ret);
		}
		else{
			int x, y; scanf("%d %d",&x,&y);
			swap(b[x], b[y]);
			x = b[x], y = b[y];
			swap(revb[x], revb[y]);
			bit.remove(reva[x], A[reva[x]]);
			bit.remove(reva[y], A[reva[y]]);
			swap(A[reva[x]], A[reva[y]]);
			bit.add(reva[x], A[reva[x]]);
			bit.add(reva[y], A[reva[y]]);
		}
	}
}