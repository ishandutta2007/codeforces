#include <bits/stdc++.h>
typedef long long lint;
typedef long double llf;
using namespace std;
typedef pair<int, int> pi;

struct node{
	int sum;
	node *l, *r;
	node(){
		sum = 0;
		l = r = NULL;
	}
}*tree[100005];

void init(node *p, int s, int e){
	if(s == e) return;
	p->l = new node();
	p->r = new node();
	int m = (s+e)/2;
	init(p->l, s, m);
	init(p->r, m+1, e);
}

void add(node *prv, node *cur, int pos, int s, int e){
	cur->sum = prv->sum + 1;
	if(s == e){
		return;
	}
	int m = (s+e)/2;
	if(pos <= m){
		cur->l = new node();
		cur->r = prv->r;
		add(prv->l, cur->l, pos, s, m);
	}
	else{
		cur->r = new node();
		cur->l = prv->l;
		add(prv->r, cur->r, pos, m+1, e);
	}
}

int getsum(node *p, int s, int e, int ps, int pe){
	if(e < ps || pe < s) return 0;
	if(s <= ps && pe <= e) return p->sum;
	int pm = (ps+pe)/2;
	return getsum(p->l, s, e, ps, pm) + getsum(p->r, s, e, pm+1, pe);
}

int getkth(node *p, int s, int e, int k){
	if(s == e) return s;
	int m = (s+e)/2;
	if(k <= p->l->sum) return getkth(p->l, s, m, k);
	return getkth(p->r, m+1, e, k - p->l->sum);
}


int n, a[100005], nxt[100005];
vector<int> seq[100005];

int getnxt(int pos, int cnt){
	int t = getsum(tree[pos], 1, pos-1, 1, n);
	cnt += t + 1;
	if(tree[pos]->sum < cnt) return n+1;
	else return getkth(tree[pos], 1, n, cnt);
}

int main(){
	map<int, int> mp;
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		if(mp.find(a[i]) != mp.end()) nxt[i] = mp[a[i]];
		mp[a[i]] = i;
		seq[nxt[i]].push_back(i);
	}
	tree[0] = new node();
	init(tree[0], 1, n);
	for(int i=1; i<=n; i++){
		node *prv = tree[i-1];
		for(auto &j : seq[i-1]){
			node *nxt = new node();
			add(prv, nxt, j, 1, n);
			prv = nxt;
		}
		tree[i] = prv;
	}
	for(int i=1; i<=n; i++){
		int ans = 0, pos = 1;
		while(pos <= n){
			int l = getnxt(pos, i);
			ans++;
			pos = l;
		}
		printf("%d ", ans);
	}
}