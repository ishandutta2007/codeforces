// Krzysztof Boryczka
#pragma GCC optimize("O3")
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

const int N=310;

int t[N][N];
int a[N];

void solve(){
	int n;
	cin>>n;
	FOR(i, 1, n) FOR(j, 1, n) cin>>t[i][j];
	FOR(i, 1, n) cin>>a[i];
	set<ii> v;
	FOR(i, 1, n){
		ii gosc={0, 0};
		FOR(j, 1, n) if(a[j]<=i){
			if(gosc.st){
				gosc.nd=a[j];
				break;
			}
			else gosc.st=a[j];
		}
		v.insert(gosc);
	}
	FOR(i, 1, n){
		FOR(j, 1, n){
			if(t[i][j] == i) continue;
			auto pt=v.lower_bound({t[i][j], -inf});
			if(v.count({i, t[i][j]}) || (pt != v.end() && (*pt).st == t[i][j])){
				cout<<t[i][j]<<sp;
				break;
			}
		}
	}
	cout<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt){
	// 	cout<<"Case #"<<te<<": ";
	// 	solve();
	// }
	solve();
	return 0;
}