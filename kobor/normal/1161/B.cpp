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

const int N=1e5+5, M=2e5+5;
const ll mod=2e9+11;
const ll pp[2]={(ll)2e5+23, (ll)2e5+29};

vi pkt[N];
vector<ll> s;
int ans[N], n;
ll prefhasz[2*M+15][2];
ll p[2*M+15][2];

int circ(int l, int r){
	if(r>l) return r-l;
	return n+r-l;
}

ll gethasz(int l, int r, int kt){
	return ((prefhasz[r][kt]-prefhasz[l-1][kt]*p[r-l+1][kt])%mod+mod)%mod;
}

void f(int dl){
	int ile=SIZE(pkt[dl]), sumka=0, pr;
	if(ile==1) return;
	s.clear(); s.pb(0);
	FOR(i, 0, ile-2) s.pb(pkt[dl][i+1]-pkt[dl][i]);
	s.pb(circ(pkt[dl].back(), pkt[dl][0]));
	FOR(i, 1, ile) s.pb(s[i]);
	FOR(i, 1, ile*2){
		prefhasz[i][0]=(prefhasz[i-1][0]*pp[0]+s[i])%mod;
		prefhasz[i][1]=(prefhasz[i-1][1]*pp[1]+s[i])%mod;
	}
	FOR(i, 1, ile-1){
		sumka+=s[i];
		pr=ile;
		if(ile%i) pr+=i-ile%i;
		if(gethasz(1, pr-i, 0)==gethasz(i+1, pr, 0) && gethasz(1, pr-i, 1)==gethasz(i+1, pr, 1)) ans[sumka]++;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int m, a, b, odp=0;
	p[0][0]=p[0][1]=1;
	FOR(i, 1, 2*M+10){
		p[i][0]=p[i-1][0]*pp[0]%mod;
		p[i][1]=p[i-1][1]*pp[1]%mod;
	}
	cin>>n>>m;
	FOR(i, 1, m){
		cin>>a>>b;
		a--; b--;
		if(circ(b, a)<circ(a, b)) swap(a, b);
		if(circ(a, b)*2==n) pkt[circ(a, b)].pb(b);
		pkt[circ(a, b)].pb(a);
	}
	FOR(i, 1, n){
		sort(pkt[i].begin(), pkt[i].end());
		if(SIZE(pkt[i])){
			f(i);
			odp++;
		}
	}
	FOR(i, 1, n-1){
		if(ans[i]==odp){
			cout<<"Yes\n";
			return 0;
		}
	}
	cout<<"No\n";
	return 0;
}