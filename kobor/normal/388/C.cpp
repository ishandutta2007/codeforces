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

int n, s, sum1, sum2;
int tab[110];
vi rest;

void solve(){
	cin>>n;
	FOR(i, 1, n){
		cin>>s;
		FOR(j, 1, s) cin>>tab[j];
		FOR(j, 1, s/2) sum1+=tab[j];
		FOR(j, (s+3)/2, s) sum2+=tab[j];
		if(s%2) rest.pb(tab[s/2+1]);
	}
	sort(rest.rbegin(), rest.rend());
	FOR(i, 0, SIZE(rest)-1){
		if(i%2) sum2+=rest[i];
		else sum1+=rest[i];
	}
	cout<<sum1<<sp<<sum2<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}