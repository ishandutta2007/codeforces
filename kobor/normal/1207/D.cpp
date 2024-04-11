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

const int mod=998244353;
const int N=3e5+5;

int cnt1[N], cnt2[N];
int fact[N]={1};
vi elo[N];

void solve(){
	int n, a, b, f1=1, f2=1, f3=1, maksiu=-1, akt, ile;
	cin>>n;
	FOR(i, 1, n) fact[i]=(ll)fact[i-1]*i%mod;
	FOR(i, 1, n){
		cin>>a>>b;
		cnt1[a]++;
		cnt2[b]++;
		elo[a].pb(b);
	}
	FOR(i, 1, n){
		f1=(ll)f1*fact[cnt1[i]]%mod;
		f2=(ll)f2*fact[cnt2[i]]%mod;
	}
	FOR(i, 1, n){
		if(!SIZE(elo[i])) continue;
		sort(elo[i].begin(), elo[i].end());
		if(elo[i].front()<maksiu){
			f3=0;
			break;
		}
		akt=-1;
		ile=0;
		for(auto &x: elo[i]){
			if(x!=akt){
				f3=(ll)f3*fact[ile]%mod;
				akt=x;
				ile=0;
			}
			ile++;
		}
		f3=(ll)f3*fact[ile]%mod;
		maksiu=elo[i].back();
	}
	cout<<((ll)fact[n]+mod*2-f1-f2+f3)%mod<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}