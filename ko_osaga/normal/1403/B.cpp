#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
using pi = pair<int, int>;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
const int MAXN = 400005;

struct bit{
	int tree[MAXN];
	void add(int x, int v){
		for(int i=x; i<MAXN; i+=i&-i) tree[i] += v;
	}
	int query(int x){
		int ret = 0;
		for(int i=x; i; i-=i&-i) ret += tree[i];
		return ret;
	}
}bit;

int n, q, a[MAXN];
vector<pi> hit[MAXN];
int arr[MAXN], dap[MAXN];

int main(){
	scanf("%d %d",&n,&q);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		a[i] = i - a[i];
		if(a[i] < 0) a[i] = n + 1;
	}
	for(int i=0; i<q; i++){
		int x, y; scanf("%d %d",&x,&y);
		hit[n - y].emplace_back(x + 1, i);
	}
	int ptr = 0;
	for(int i=1; i<=n; i++){
		int s = 0, e = i;
		while(s != e){
			int m = (s + e + 1) / 2;
			if(bit.query(m) >= a[i]) s = m;
			else e = m - 1;
		}
		bit.add(1, +1);
		bit.add(s + 1, -1);
		for(auto &[pos, idx] : hit[i]){
			dap[idx] = bit.query(pos);
		}
	}
	for(int i=0; i<q; i++) printf("%d\n", dap[i]);
}