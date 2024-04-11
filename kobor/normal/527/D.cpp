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

const int N=2e5+5;

int n, a, b, ans, konc=-inf;
ii t[N];

void solve(){
	cin>>n;
	FOR(i, 1, n){
		cin>>a>>b;
		t[i]={a+b, a-b};
	}
	sort(t+1, t+n+1);
	FOR(i, 1, n){
		if(t[i].nd>=konc){
			konc=t[i].st;
			ans++;
		}
	}
	cout<<ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}