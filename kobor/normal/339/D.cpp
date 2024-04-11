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

const int M2=1<<17;

int tree[M2*2+5];
int n, M;

void add(int pos, int val){
	bool czyor=1;
	pos+=M;
	tree[pos]=val, pos>>=1;
	while(pos){
		if(czyor) tree[pos]=tree[pos<<1]|tree[(pos<<1)^1];
		else tree[pos]=tree[pos<<1]^tree[(pos<<1)^1];
		pos>>=1, czyor^=1;
	}
}

void solve(){
	int q, a, pos, val;
	cin>>n>>q;
	M=1<<n;
	FOR(i, 0, M-1){
		cin>>a;
		add(i, a);
	}
	FOR(i, 1, q){
		cin>>pos>>val;
		add(pos-1, val);
		cout<<tree[1]<<ent;
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