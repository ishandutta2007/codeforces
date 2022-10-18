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

const int N=2010;
const int M=1<<17;

int t[N], tree[M*2+5][2], n, ans;	//0-pref, 1-suf

void add(int l, int val, int kt){
	l+=M;
	while(l){
		tree[l][kt]+=val;
		l>>=1;
	}
}

int query(int l, int r, int kt){
	int ret=0;
	l+=M; r+=M;
	while(l<=r){
		if(l&1) ret+=tree[l++][kt];
		if(!(r&1)) ret+=tree[r--][kt];
		l>>=1; r>>=1;
	}
	return ret;
}

void solve(){
	cin>>n;
	FOR(i, 1, n) cin>>t[i];
	FOR(i, 1, n) add(abs(t[i]), 1, 1);
	FOR(i, 1, n){
		ans+=min(query(0, abs(t[i])-1, 0), query(0, abs(t[i])-1, 1));
		add(abs(t[i]), 1, 0);
		add(abs(t[i]), -1, 1);
	}
	cout<<ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}