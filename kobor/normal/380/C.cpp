//Krzysztof Boryczka
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

typedef pair<ii, int> naw;	//zamyk po lewej, otw po prawej, wyn

const int M=1<<20;

naw t[2*M+5];
vi v;

naw match(naw a, naw b){
	return {{a.st.st+max(b.st.st-a.st.nd, 0), b.st.nd+max(a.st.nd-b.st.st, 0)}, a.nd+b.nd+min(a.st.nd, b.st.st)};
}

int query(int l, int r){
	naw ret={{0, 0}, 0};
	l+=M-1; r+=M-1;
	while(l<=r){
		if(l&1) ret=match(ret, t[l++]);
		if((r&1)^1) v.pb(r--);
		l>>=1;
		r>>=1;
	}
	FORD(i, SIZE(v)-1, 0) ret=match(ret, t[v[i]]);
	v.clear();
	return ret.nd;
}

void solve(){
	string s;
	int q, a, b;
	cin>>s;
	FOR(i, 0, SIZE(s)-1){
		if(s[i]=='(') t[i+M].st.nd++;
		else t[i+M].st.st++;
	}
	FORD(i, M-1, 1) t[i]=match(t[i*2], t[i*2+1]);
	cin>>q;
	FOR(i, 1, q){
		cin>>a>>b;
		cout<<query(a, b)*2<<ent;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}