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

const int N=1e5+5;

int n, a[N], b[N];
int diff;

void solve(){
	diff=-1;
	cin>>n;
	FOR(i, 1, n) cin>>a[i];
	FOR(i, 1, n) cin>>b[i];
	FOR(i, 1, n){
		int rozn=b[i]-a[i];
		if(rozn<0){
			cout<<"NO\n";
			return;
		}
		if(rozn==0){
			if(diff>0) diff=-2;
			continue;
		}
		if(diff==-1) diff=rozn;
		else if(diff==-2 || diff!=rozn){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tt; cin>>tt;
	FOR(te, 1, tt)
	solve();
	return 0;
}