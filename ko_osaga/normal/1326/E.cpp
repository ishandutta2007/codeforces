#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<int, int>;
const int MAXN = 600005;
const int MAXT = 2100000;

struct node{
	int sum, sfx;
	node operator+(const node &n)const{
		return (node){sum + n.sum, max(n.sfx, n.sum + sfx)};
	}
};

	node sex(int x){
		return (node){x, max(x, 0)};
	}
struct seg{
	node tree[MAXT];
	int lim;
	void init(int n){
		for(lim = 1; lim <= n; lim <<= 1);
	}
	void upd(int x, int v){
		x += lim;
		tree[x] = sex(v);
		for(int i=x/2; i>=1; i>>=1){
			tree[i] = tree[2*i] + tree[2*i+1];
		}
	}
}seg;

int n;
int rev[MAXN], p[MAXN];

int main(){
	scanf("%d",&n);
	seg.init(2*n);
	for(int i=1; i<=n; i++) scanf("%d",&p[i]), rev[p[i]] = i;
	int ptr = n + 1;
	for(int i=1; i<=n; i++){
		while(seg.tree[1].sfx <= 0){
			ptr--;
			seg.upd(rev[ptr] * 2 - 1, 1);
		}
		printf("%d ", ptr);
		int x; scanf("%d",&x);
		seg.upd(2 * x, -1);
	}
}