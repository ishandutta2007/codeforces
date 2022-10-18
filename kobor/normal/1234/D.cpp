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

const int M=1<<17;

int tree[26][M*2+5];

void add(int pos, int val, int nr){
	pos+=M;
	while(pos){
		tree[nr][pos]+=val;
		pos>>=1;
	}
}

int query(int l, int r, int nr){
	int ret=0;
	l+=M, r+=M;
	while(l<=r){
		if(l&1) ret+=tree[nr][l++];
		if((r&1)^1) ret+=tree[nr][r--];
		l>>=1, r>>=1;
	}
	return ret;
}

void solve(){
	int a, b, c;
	char d;
	string s;
	cin>>s;
	FOR(i, 1, SIZE(s)) add(i, 1, s[i-1]-'a');
	int q;
	cin>>q;
	FOR(i, 1, q){
		cin>>a>>b;
		if(a==1){
			cin>>d;
			add(b, -1, s[b-1]-'a');
			s[b-1]=d;
			add(b, 1, s[b-1]-'a');
		}
		else{
			cin>>c;
			int ans=0;
			FOR(j, 0, 25) ans+=(query(b, c, j)>0);
			cout<<ans<<ent;
		}
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