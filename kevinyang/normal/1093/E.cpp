#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
//#define int long long
using namespace std; using namespace __gnu_pbds;
typedef long long ll;
typedef pair<int, int> pii;
template <typename T, class cmp = less<T>> using ordered_set = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T, typename X = null_type> using hash_map = gp_hash_table<T, X>;
ordered_set<int> bit[200005];
int n,m;
inline void update(int x, int y){
	for(int a = x; a<=200000; a+=a&-a){
		bit[a].insert(y);
	}
}
inline void update2(int x, int y){
	for(int a = x; a<=200000; a+=a&-a){
		bit[a].erase(y);
	}
}
inline int query(int x, int y){
	int sum = 0;
	for(int a = x; a; a-=a&-a){
		sum+=bit[a].order_of_key(y+1);
	}
	return sum;
}
const int mxn = 200005;
int a[mxn], b[mxn], rev[mxn], idx[mxn];
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i<=n; i++){
		cin >> a[i];
	}
	for(int i = 1; i<=n; i++){
		cin >> b[i];
	}
	for(int i = 1; i<=n; i++){
		rev[a[i]] = i;
	}
	for(int i = 1; i<=n; i++){
		idx[b[i]] = i;
	}
	for(int i = 1; i<=n; i++){
		update(i,idx[a[i]]);
	}
	for(int i = 1; i<=m; i++){
		int cm;
		cin >> cm;
		if(cm==1){
			int a,b,c,d;
			cin >> a >> c >> b >> d;
			cout << query(c,d)-query(a-1,d)-query(c,b-1)+query(a-1,b-1) << "\n";
		}
		else{
			int x,y;
			cin >> x >> y;
			update2(rev[b[x]],x);
			update2(rev[b[y]],y);
			swap(b[x],b[y]);
			idx[b[x]] = x; idx[b[y]] = y;
			update(rev[b[x]],x);
			update(rev[b[y]],y);
		}
	}
	return 0;
}