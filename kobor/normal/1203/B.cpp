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

const int M=1e4+5;

int n, mink, maxk, il;
int cnt[M], t[410];

void solve(){
	memset(cnt, 0, sizeof(cnt));
	cin>>n; n*=4;
	FOR(i, 1, n) cin>>t[i], cnt[t[i]]++;
	mink=*min_element(t+1, t+n+1);
	maxk=*max_element(t+1, t+n+1);
	il=mink*maxk;
	FOR(i, 1, M-3){
		if(!cnt[i]) continue;
		if(cnt[i]&1 || il%i || cnt[i]!=cnt[il/i]){
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