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

const int N=2e5+5;

int n, q, p, x, a;
int t[N], daj[N], czas[N];

void solve(){
	cin>>n;
	FOR(i, 1, n) cin>>t[i];
	cin>>q;
	FOR(i, 1, q){
		cin>>a;
		if(a==1){
			cin>>p>>x;
			t[p]=x;
			czas[p]=i;
		}
		else{
			cin>>x;
			daj[i]=x;
		}
	}
	FORD(i, q, 0) daj[i]=max(daj[i], daj[i+1]);
	FOR(i, 1, n) cout<<max(t[i], daj[czas[i]])<<sp;
	cout<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}