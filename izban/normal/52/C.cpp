#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>
#include <string>
#include <ctime> 
#include <cstdlib>
#include <set>
#include <sstream>
#include <queue>
#include <functional>
#include <memory>
#include <assert.h>

#define sqr(x) ((x)*(x))
#define ll long long

using namespace std;

#pragma comment(linker,"/STACK:256000000")

const int maxn=1<<18;
const int mod=1e9;
const int inf=(1e9)+1;

typedef struct item * pitem;
struct item {
	int prior,cnt;
	ll value,mn,add;
	pitem l,r;
};

ll mn(pitem t) {
	return (t?t->mn+t->add:inf);
}

int cnt(pitem t) {
	return (t?t->cnt:0);
}

void upd(pitem &t) {
	if (t) {
		t->cnt=cnt(t->l)+cnt(t->r)+1;
		t->mn=min(t->value,min(mn(t->l),mn(t->r)));
	}
}

void push(pitem &t) {
	if (!t) return;
	if (t->l) t->l->add+=t->add;
	if (t->r) t->r->add+=t->add;
	t->value+=t->add;
	t->mn+=t->add;
	t->add=0;
}

void split(pitem t, pitem &l, pitem &r, int key, int add=0) {
	if (!t)
		return void(l=r=0);
	push(t);
	int cur=add+cnt(t->l);
	if (key <= cur)
		split(t->l,l,t->l,key,add), r=t;
	else
		split(t->r,t->r,r,key,cur+1), l=t;
	upd(t);
}

void merge(pitem &t, pitem l, pitem r) {
	push(l); push(r);
	if (!l|| !r)
		t=l?l:r;
	else if (l->prior > r->prior)
		merge(l->r,l->r,r), t=l;
	else
		merge(r->l,l,r->l), t=r;
	upd(t);
}

void insert(pitem &t, pitem it, int pos) {
	pitem t1,t2;
	split(t,t1,t2,pos);
	merge(t1,t1,it);
	merge(t,t1,t2);
}

void upd1(pitem &t, int l, int r, int x) {
	pitem t1,t2,t3;
	split(t,t1,t2,l);
	split(t2,t2,t3,r-l+1);
	t2->add+=x;
	merge(t,t1,t2);
	merge(t,t,t3);
}

ll get(pitem &t, int l, int r) {
	pitem t1,t2,t3;
	split(t,t1,t2,l);
	split(t2,t2,t3,r-l+1);
	ll ans=mn(t2);
	merge(t,t1,t2);
	merge(t,t,t3);
	return ans;
}

string s;
int n,m;
item a[maxn];
pitem t;
vector<int> v(4);

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	scanf("%d\n",&n);
	for (int i=0; i<n; i++) {
		scanf("%I64d",&a[i].value);
		a[i].prior=(rand()<<15)+rand();
		insert(t,&a[i],i);
	}
	scanf("\n");
	scanf("%d\n",&m);
	for (int i=0; i<m; i++) {
		getline(cin,s);
		if (sscanf(s.c_str(),"%d%d%d",&v[0],&v[1],&v[2])==2) {
			if (v[1]>=v[0]) {
				ll ans=get(t,v[0],v[1]);
				printf("%I64d\n",ans);
			}
			else {
				ll ans=inf;
				ans=min(ans,get(t,v[0],n-1));
				ans=min(ans,get(t,0,v[1]));
				printf("%I64d\n",ans);
			}
		} else {
			if (v[1]>=v[0]) {
				upd1(t,v[0],v[1],v[2]);
			}
			else {
				upd1(t,v[0],n-1,v[2]);
				upd1(t,0,v[1],v[2]);
			}
		}
	}
	return 0;
}