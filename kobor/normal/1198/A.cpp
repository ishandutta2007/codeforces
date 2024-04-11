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

const int N=4e5+5;

int n, k, I, rozn, j, ile, akt, ans=inf;
int t[N];
map<int, int> wart;

void dodaj(int v){
	v=t[v];
	if(!wart[v]) akt++;
	wart[v]++;
}

void usun(int v){
	v=t[v];
	wart[v]--;
	if(!wart[v]) akt--;
}

void solve(){
	cin>>n>>I;
	FOR(i, 1, n) cin>>t[i];
	sort(t+1, t+n+1);
	k=min(8*I/n, 25);
	rozn=pow(2, k);
	FOR(i, 1, n){
		while(j<=n && akt<=rozn) dodaj(++j);
		ans=min(ans, n-(j-i));
		usun(i);
	}
	cout<<ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}