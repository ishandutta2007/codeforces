//Krzysztof Boryczka
#pragma GCC optimize "O3"
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3f;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)x.size())
#define pb push_back
#define st first
#define nd second
#define sp ' '
#define ent '\n'
//END OF TEMPLATE

const int M=1<<17;

int n, m;
ll tree[M*2+5], lazy[M*2+5];
set<ii> rng;

void push(int v){
	tree[v*2]+=lazy[v]/2;
	tree[v*2+1]+=lazy[v]/2;
	lazy[v*2]+=lazy[v]/2;
	lazy[v*2+1]+=lazy[v]/2;
	lazy[v]=0;
}

void add(int l, int r, ll val, int v=1, int le=1, int re=M){
	if(l>re || r<le) return;
	if(l<=le && re<=r){
		tree[v]+=val*(re-le+1);
		lazy[v]+=val*(re-le+1);
		return;
	}
	int mid=(le+re)/2;
	push(v);
	add(l, r, val, v*2, le, mid);
	add(l, r, val, v*2+1, mid+1, re);
	tree[v]=tree[v*2]+tree[v*2+1];
}

ll query(int l, int r, int v=1, int le=1, int re=M){
	if(l>re || r<le) return 0;
	if(l<=le && re<=r) return tree[v];
	int mid=(le+re)/2;
	push(v);
	ll ret=query(l, r, v*2, le, mid)+query(l, r, v*2+1, mid+1, re);
	tree[v]=tree[v*2]+tree[v*2+1];
	return ret;
}

void paint(int l, int r, int val){
	auto x=prev(rng.upper_bound({l, inf}));
	while((*x).st<=r){
		add(max((*x).st, l), min((*next(x)).st-1, r), abs(val-(*x).nd));
		ii dodaj1, dodaj2;
		if((*x).st<l) dodaj1=*x;
		if((*next(x)).st-1>r) dodaj2={r+1, (*x).nd};
		rng.erase(prev(++x));
		rng.insert(dodaj1); rng.insert(dodaj2);
	}
	rng.insert({l, val});
}

void solve(){
	int c, a, b;
	cin>>n>>m;
	FOR(i, 0, n+1) rng.insert({i, i});
	FOR(i, 1, m){
		cin>>c>>a>>b;
		if(c==1){
			cin>>c;
			paint(a, b, c);
		}
		else cout<<query(a, b)<<ent;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}