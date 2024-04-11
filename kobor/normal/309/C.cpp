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

const int M=31;

int n, m, a, ans;
int miej[M+2];
vi zysk[M+2];

void solve(){
	cin>>n>>m;
	FOR(j, 1, n){
		cin>>a;
		FOR(i, 0, M){
			miej[i]+=(a&1);
			a/=2;
		}
	}
	FOR(i, 1, m){
		cin>>a;
		zysk[a].pb(1);
	}
	FOR(i, 0, M){
		sort(zysk[i].begin(), zysk[i].end());
		while(SIZE(zysk[i]) && miej[i]){
			ans+=zysk[i].back();
			zysk[i].pop_back();
			miej[i]--;
		}
		while(SIZE(zysk[i])){
			auto v=zysk[i].back();
			zysk[i].pop_back();
			int u=0;
			if(SIZE(zysk[i])){
				u=zysk[i].back();
				zysk[i].pop_back();
			}
			zysk[i+1].pb(v+u);
		}
	}
	cout<<ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}