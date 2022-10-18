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

const int mod=1e9+123;
const int N=6e5+5;
const int pp[2]={5, 7};
int p[2][N]={{1}, {1}};

set<ii> hasze;
string s;

void dodaj(){
	int hasz[2]={0, 0};
	FOR(k, 0, 1) FOR(i, 0, SIZE(s)-1) hasz[k]=(hasz[k]+(ll)p[k][i]*(s[i]-'a'+1))%mod;
	hasze.insert({hasz[0], hasz[1]});
}

bool query(){
	int bhasz[2], hasz[2]={0, 0};
	FOR(k, 0, 1) FOR(i, 0, SIZE(s)-1) hasz[k]=(hasz[k]+(ll)p[k][i]*(s[i]-'a'+1))%mod;
	FOR(k, 0, 1) bhasz[k]=hasz[k];
	FOR(i, 0, SIZE(s)-1){
		FOR(k, 0, 1) hasz[k]=((hasz[k]-(ll)p[k][i]*(s[i]-'a'+1)+(ll)p[k][i])%mod+mod)%mod;
		if(hasz[0]!=bhasz[0] && hasz[1]!=bhasz[1] && hasze.find({hasz[0], hasz[1]})!=hasze.end()) return 1;
		FOR(k, 0, 1) hasz[k]=bhasz[k];

		FOR(k, 0, 1) hasz[k]=((hasz[k]-(ll)p[k][i]*(s[i]-'a'+1)+(ll)p[k][i]*2)%mod+mod)%mod;
		if(hasz[0]!=bhasz[0] && hasz[1]!=bhasz[1] && hasze.find({hasz[0], hasz[1]})!=hasze.end()) return 1;
		FOR(k, 0, 1) hasz[k]=bhasz[k];

		FOR(k, 0, 1) hasz[k]=((hasz[k]-(ll)p[k][i]*(s[i]-'a'+1)+(ll)p[k][i]*3)%mod+mod)%mod;
		if(hasz[0]!=bhasz[0] && hasz[1]!=bhasz[1] && hasze.find({hasz[0], hasz[1]})!=hasze.end()) return 1;
		FOR(k, 0, 1) hasz[k]=bhasz[k];
	}
	return 0;
}

void solve(){
	FOR(k, 0, 1) FOR(i, 1, N-3) p[k][i]=(ll)p[k][i-1]*pp[k]%mod;
	int n, m;
	cin>>n>>m;
	FOR(i, 1, n){
		cin>>s;
		dodaj();
	}
	FOR(i, 1, m){
		cin>>s;
		cout<<(query()?"YES":"NO")<<ent;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}