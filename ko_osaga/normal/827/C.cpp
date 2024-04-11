#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int MAXN = 100005;

int n;

struct bit{
	int tree[MAXN];
	void add(int x, int v){
		while(x <= n){
			tree[x] += v;
			x += x & -x;
		}
	}
	int query(int x){
		int ret = 0;
		while(x){
			ret += tree[x];
			x -= x & -x;
		}
		return ret;
	}
}bit[4][10];

int rev[256];
char str[MAXN], buf[15];
int ord[10][MAXN], fnd[10][MAXN];

int main(){
	rev['A'] = 0, rev['C'] = 1, rev['G'] = 2, rev['T'] = 3;
	scanf("%s", str + 1);
	n = strlen(str + 1);
	for(int i=0; i<10; i++){
		iota(ord[i], ord[i] + n + 1, 0);
		sort(ord[i] + 1, ord[i] + n + 1, [&](const int &a, const int &b){
			return pi(a % (i+1), a / (i+1)) < pi(b % (i+1), b / (i+1));
		});
		for(int j=1; j<=n; j++){
			int val = str[ord[i][j]];
			bit[rev[val]][i].add(j, 1);
			fnd[i][ord[i][j]] = j;
		}
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int x;
		scanf("%d",&x);
		if(x == 1){
			int p;
			scanf("%d %s", &p, buf);
			int pval = rev[str[p]];
			int nval = rev[*buf];
			str[p] = *buf;
			for(int i=0; i<10; i++){
				int pos = fnd[i][p];
				bit[pval][i].add(pos, -1);
				bit[nval][i].add(pos, 1);
			}
		}
		else{
			int s, e;
			scanf("%d %d %s",&s,&e,buf);
			int l = strlen(buf);
			auto cmp = [&](const int &a, const int &b){
				return pi(a % l, a / l) < pi(b % l, b / l);
			};
			int ret = 0;
			for(int i=0; i<l; i++){
				int idx = 0;
				int st = s;
				while(st % l != i) st++, idx++;
				int ed = e+1;
				while(ed % l != i) ed++;
				int chr = rev[buf[idx]];
				auto lb = lower_bound(ord[l-1] + 1, ord[l-1] + n + 1, st, cmp) - ord[l-1];
				auto ub = lower_bound(ord[l-1] + 1, ord[l-1] + n + 1, ed, cmp) - ord[l-1];
				ret += bit[chr][l-1].query(ub - 1) - bit[chr][l-1].query(lb - 1);
			}
			printf("%d\n", ret);
		}
	}
}