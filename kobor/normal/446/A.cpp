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

const int N=1e5+5;

int n;
int lewo[N], prawo[N], t[N]={inf}, ans;

void solve(){
	cin>>n;
	FOR(i, 1, n) cin>>t[i];
	FOR(i, 1, n){
		lewo[i]=1;
		if(t[i]>t[i-1]) lewo[i]+=lewo[i-1];
	}
	FORD(i, n, 1){
		prawo[i]=1;
		if(t[i]<t[i+1]) prawo[i]+=prawo[i+1];
	}
	FOR(i, 1, n){
		if(t[i-1]<t[i+1]-1) ans=max(ans, lewo[i-1]+1+prawo[i+1]);
		else ans=max({ans, lewo[i-1]+1, prawo[i+1]+1});
	}
	cout<<ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}