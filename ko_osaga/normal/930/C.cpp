#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
typedef pair<int, int> pi;
typedef long long lint;

int n, q;
int cnt[MAXN];
int d1[MAXN], d2[MAXN];

struct seg{
	int tree[MAXN];
	void clear(){
		memset(tree, 0, sizeof(tree));
	}
	void update(int x, int v){
		x ++;
		while( x < MAXN){
			tree[x] = max(tree[x], v);
			x += x & -x;
		}
	}
	int query(int x){
		x++;
		int ret = 0;
		while(x){
			ret = max(ret, tree[x]);
			x -= x & -x;
		}
		return ret;
	}
}seg;

int main(){
	scanf("%d %d",&q,&n);
	while(q--){
		int l, r;
		scanf("%d %d",&l,&r);
		cnt[l]++;
		cnt[r+1]--;
	}
	for(int i=1; i<=n; i++) cnt[i] += cnt[i-1];
	for(int i=1; i<=n; i++){
		d1[i] = seg.query(cnt[i]) + 1;
		seg.update(cnt[i], d1[i]);
	}
	seg.clear();
	for(int i=n; i; i--){
		d2[i] = seg.query(cnt[i]) + 1;
		seg.update(cnt[i], d2[i]);
	}
	int ans = 0;
	for(int i=1; i<=n; i++) ans = max(ans, d1[i] + d2[i] - 1);
	cout << ans << endl;
}