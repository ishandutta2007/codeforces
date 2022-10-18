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
const int K=60;
int n;
int tree[M*2+5][K];

void add(int pos, int val){
	pos+=M;
	FOR(i, 0, K-1){
		tree[pos][i]=1;
		if(i%val==0) tree[pos][i]++;
	}
	pos>>=1;
	while(pos){
		FOR(i, 0, K-1) tree[pos][i]=tree[pos*2][i]+tree[pos*2+1][(i+tree[pos*2][i])%60];
		pos>>=1;
	}
}

int query(int l, int r){
	int lewy[K], prawy[K], copy[K];
	FOR(i, 0, K-1) lewy[i]=prawy[i]=copy[i]=0;
	l+=M; r+=M;
	while(l<=r){
		if(l&1){
			FOR(i, 0, K-1) lewy[i]=lewy[i]+tree[l][(i+lewy[i])%60];
			l++;
		}
		if(!(r&1)){
			FOR(i, 0, K-1) copy[i]=prawy[i];
			FOR(i, 0, K-1) prawy[i]=tree[r][i]+copy[(i+tree[r][i])%60];
			r--;
		}
		l>>=1; r>>=1;
	}
	return lewy[0]+prawy[lewy[0]%60];
}

void solve(){
	int a, b, q;
	char c;
	cin>>n;
	FOR(i, 1, n){
		cin>>a;
		add(i, a);
	}
	cin>>q;
	FOR(i, 1, q){
		cin>>c>>a>>b;
		if(c=='A') cout<<query(a, b-1)<<ent;
		else add(a, b);
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