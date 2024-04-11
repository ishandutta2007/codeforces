#include <cstdio>
#include <algorithm>
using namespace std;

struct seg{
	int tree[270000], hlazy[270000], lazyval[270000];
	void lazydown(int ps, int pe, int p){
		if(hlazy[p] == 0) return;
		int pm = (ps + pe) / 2;
		hlazy[p] = 0;
		hlazy[2*p] = hlazy[2*p+1] = 1;
		tree[2*p] = (pm - ps + 1) * lazyval[p];
		tree[2*p+1] = (pe - pm) * lazyval[p];
		lazyval[2*p] = lazyval[2*p+1] = lazyval[p];
	}
	void fill(int s, int e, int ps, int pe, int p, int v){
		if(e < ps || pe < s) return;
		if(s <= ps && pe <= e){
			tree[p] = (pe - ps + 1) * v;
			hlazy[p] = 1;
			lazyval[p] = v;
			return;
		}
		int pm = (ps + pe) / 2;
		lazydown(ps, pe, p);
		fill(s,e,ps,pm,2*p,v);
		fill(s,e,pm+1,pe,2*p+1,v);
		tree[p] = tree[2*p] + tree[2*p+1];
	}
	int sum(int s, int e, int ps, int pe, int p){
		if(e < ps || pe < s) return 0;
		if(s <= ps && pe <= e) return tree[p];
		int pm = (ps + pe) / 2;
		lazydown(ps, pe, p);
		return sum(s,e,ps,pm,2*p) + sum(s,e,pm+1,pe,2*p+1);
	}
}seg[26];

int n, q;
char str[100005];

int main(){
	scanf("%d %d %s",&n,&q,str);
	for(int i=0; str[i]; i++){
		seg[str[i] - 'a'].fill(i+1,i+1,1,n,1,1);
	}
	for(int i=0; i<q; i++){
		int s, e, x;
		scanf("%d %d %d",&s,&e,&x);
		int sum[26];
		for(int i=0; i<26; i++){
			sum[i] = seg[i].sum(s,e,1,n,1);
		}
		for(int i=0; i<26; i++){
			seg[i].fill(s,e,1,n,1,0);
		}
		if(x == 0){
			int p = s;
			for(int i=25; i>=0; i--){
				seg[i].fill(p,p+sum[i] - 1,1,n,1,1);
				p += sum[i];
			}
		}
		else{
			int p = s;
			for(int i=0; i<26; i++){
				seg[i].fill(p,p+sum[i] - 1,1,n, 1,1);
				p += sum[i];
			}
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<26; j++){
			if(seg[j].sum(i+1,i+1,1,n,1)){
				putchar(j + 'a');
				break;
			}
		}
	}
}