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

const int N=2e5+5;
const int M=1<<18;

pair<ll, int> tree[M*2+5];
ll lazy[M*2+5];
int n, ans[N];

void push(int v){
	tree[v*2].st+=lazy[v];
	tree[v*2+1].st+=lazy[v];
	lazy[v*2]+=lazy[v];
	lazy[v*2+1]+=lazy[v];
	lazy[v]=0;
}

void add(int l, int r, ll val, int v=1, int le=1, int re=M-1){
	if(l>r || l>re || r<le) return;
	if(le>=l && re<=r){
		tree[v].st+=val;
		lazy[v]+=val;
		return;
	}
	int mid=(le+re)/2;
	push(v);
	add(l, r, val, v*2, le, mid);
	add(l, r, val, v*2+1, mid+1, re);
	tree[v]=min(tree[v*2], tree[v*2+1]);
}

void solve(){
	int pom;
	cin>>n;
	FOR(i, 1, n){
		cin>>tree[i+M-1].st;
		tree[i+M-1].nd={-i};
	}
	FORD(i, M-1, 1) tree[i]=min(tree[i*2], tree[i*2+1]);
	FOR(i, 1, n){
		pom=-tree[1].nd;
		ans[pom]=i;
		add(pom, pom, INF);
		add(pom+1, n, -i);
	}
	FOR(i, 1, n) cout<<ans[i]<<sp;
	cout<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}