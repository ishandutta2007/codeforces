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

int t[8][3], cnt[4];
vector<ll> dists;
ll minek;

ll dist(int a, int b){
	ll ret=0;
	FOR(j, 0, 2) ret+=(ll)(t[a][j]-t[b][j])*(t[a][j]-t[b][j]);
	return ret;
}

bool git(){
	bool ok=1;
	FOR(i, 0, 7) FOR(j, i+1, 7) dists.pb(dist(i, j));
	minek=*min_element(dists.begin(), dists.end());
	for(auto &x: dists){
		if(minek==0 || x%minek!=0 || x/minek>3){
			ok=0;
			break;
		}
		cnt[x/minek]++;
	}
	if(ok) if(cnt[1]!=12 || cnt[2]!=12 || cnt[3]!=4) ok=0;
	FOR(i, 1, 3) cnt[i]=0;
	dists.clear();
	return ok;
}

bool perm(int ind){
	if(ind==8) return git();
	sort(t[ind], t[ind]+3);
	do{
		if(perm(ind+1)) return 1;
	}while(next_permutation(t[ind], t[ind]+3));
	return 0;
}

void solve(){
	FOR(i, 0, 7) FOR(j, 0, 2) cin>>t[i][j];
	if(perm(1)){
		cout<<"YES\n";
		FOR(i, 0, 7){
			FOR(j, 0, 2) cout<<t[i][j]<<sp;
			cout<<ent;
		}
	}
	else cout<<"NO\n";
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}