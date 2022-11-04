#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// treap is useless for competitive programming
// implicit treap is a segment tree but you can swap/reverse segments
// you can also insert/erase kth element

// DON'T FORGET TO MODIFY TRES() - calculating result without propagating lazy
#define NEUTRAL_DIFF 0 // the values will never be this extreme
#define NEUTRAL_SAME 0 // I will never update the tree with this
#define COMBINE_DIFF(a, b) ((a)) // combining 2 different nodes (a is data)
#define COMBINE_SAME(a, b) ((a)+(b)) // comb. 2 of the same node (b is the newer)

struct Treap;
mt19937_64 gen(std::random_device{}());

struct Treap {
	ll prior=gen();
	ll data=NEUTRAL_DIFF,lazy=NEUTRAL_SAME;
	bool rev=false;
	ll tsz=1,tres=NEUTRAL_DIFF; // sz of tree below me, res of data below me (+ me) (sum/max/prod..)
	vector<Treap*>kids={0,0};
	Treap(ll data=NEUTRAL_DIFF):data(data),tres(data){}
};

ll tsz(Treap *u){return u?u->tsz:0;}
// you can (and have to) use lazy, size, previous tres, data in calculation of tres
// you can assume they are all correct
// currently works with q:sum,u:add
ll tres(Treap *u){return u?(u->lazy==NEUTRAL_SAME?u->tres:u->tres+tsz(u)*u->lazy):NEUTRAL_DIFF;}

// needed because of merging/splitting..
// assumes lazy is already propagated
// assumes kids are recalculated
void recalc(Treap *u){
	u->tsz=1+tsz(u->kids[0])+tsz(u->kids[1]);
	u->tres=COMBINE_DIFF(u->data,COMBINE_DIFF(tres(u->kids[0]), tres(u->kids[1])));
}

void applylazy(Treap *u){
	if(u->lazy!=NEUTRAL_SAME){
		for(auto v:u->kids)if(v)v->lazy=COMBINE_SAME(v->lazy,u->lazy);
		u->data=COMBINE_SAME(u->data,u->lazy);
		u->lazy=NEUTRAL_SAME;
		recalc(u);
	}
	if(u->rev){
		swap(u->kids[0],u->kids[1]);
		for(auto v:u->kids)if(v)v->rev^=1;
		u->rev=0;
	}
}

Treap* merge(Treap *l,Treap *r){
	if(!l||!r)return l?l:r;
	applylazy(l);applylazy(r);
	if(l->prior < r->prior){
		l->kids[1]=merge(l->kids[1], r);
		recalc(l);
		return l;
	}
	else{
		r->kids[0]=merge(l,r->kids[0]);
		recalc(r);
		return r;
	}
}

// cntleft = how many nodes to skip
vector<Treap*>split(Treap *u,int cntleft) {
	if(!u)return {0,0};
	applylazy(u);
	if(tsz(u->kids[0])>=cntleft){
		auto res=split(u->kids[0],cntleft);
		u->kids[0]=res[1];
		recalc(u);
		return {res[0],u};
	}
	else{
		auto res=split(u->kids[1],cntleft-tsz(u->kids[0])-1);
		u->kids[1]=res[0];
		recalc(u);
		return {u,res[1]};
	}
}

// 0=first, inserts v to kth position
Treap* insertkth(Treap *u,Treap *v,int k){
	auto a=split(u,k);
	return merge(a[0],merge(v,a[1]));
}

// 0=first, inclusive, inclusive
Treap* erase(Treap *u,int l,int r){
	auto a=split(u,l),b=split(a[1],r-l+1);
	return merge(a[0],b[1]);
}

// 0=first, inclusive, inclusive
Treap* update(Treap *u,int l,int r,ll d) {
	auto a=split(u,l),b=split(a[1],r-l+1);
	b[0]->lazy=COMBINE_SAME(b[0]->lazy,d);
	return merge(a[0],merge(b[0],b[1]));
}

// 0=first, inclusive, inclusive
Treap* query(Treap *u,int l,int r,ll &res) {
	auto a=split(u,l),b=split(a[1],r-l+1);
	res=tres(b[0]);
	return merge(a[0],merge(b[0],b[1]));
}

// cyclical shift to the right k=0 =>same
Treap* shift(Treap *u,int k){
	auto a=split(u,tsz(u)-k);
	return merge(a[1],a[0]);
}

Treap* reverse(Treap *u,int l,int r){
	auto a=split(u,l),b=split(a[1],r-l+1);
	b[0]->rev=1;
	return merge(a[0],merge(b[0],b[1]));
}

void inorder(Treap *u){
	if(!u)return;
	applylazy(u);
	inorder(u->kids[0]);
	cout<<u->data<<" ";
	inorder(u->kids[1]);
}

const int N=200100;
Treap ts[N];

main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int n,q,m;cin>>n>>q>>m;
	Treap *root=0;
	for(int i=0;i<n;++i){
		ll x;cin>>x;
		ts[i]=Treap(x);
		root=insertkth(root,&ts[i],i);
	}
	while(q--){
		int t,l,r;cin>>t>>l>>r;--l;--r;
		if(t==1){
			auto a=split(root,l),b=split(a[1],r-l+1);
			b[0]=shift(b[0],1);
			root=merge(a[0],merge(b[0],b[1]));
		}
		if(t==2){
			root=reverse(root,l,r);
		}
//		inorder(root);cout<<endl;
	}
	ll res=0,b=0;
	for(int i=0;i<m;++i){
		cin>>b;--b;
		root=query(root,b,b,res);
		cout<<res<<" ";
	}
	cout<<endl;
}