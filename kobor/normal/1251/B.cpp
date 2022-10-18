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

const int N=55;

int n;
int dl[N], ile[2];

void solve(){
	string s;
	int ans=0, par, wolne;
	cin>>n;
	FOR(i, 1, n){
		cin>>s;
		dl[i]=SIZE(s);
		for(auto &x: s) ile[x-'0']++;
	}
	par=ile[0]/2+ile[1]/2;
	wolne=(ile[0]&1)+(ile[1]&1);
	sort(dl+1, dl+n+1);
	FOR(i, 1, n){
		if(dl[i]&1){
			if(wolne) wolne--;
			else if(par) par--, wolne++;
			else break;
			dl[i]--;
		}
		if(par>=dl[i]/2){
			ans++;
			par-=dl[i]/2;
		}
		else break;
	}
	cout<<ans<<ent;
	memset(dl, 0, sizeof(dl));
	memset(ile, 0, sizeof(ile));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tt; cin>>tt;
	FOR(te, 1, tt)
	solve();
	return 0;
}