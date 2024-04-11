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

const int N=4000;

int huh[N+5];
int ile[N+5], pt;

void solve(){
	memset(ile, 0, sizeof(ile));
	int n; cin>>n;
	pt=N;
	while(n){
		ile[pt]+=n/huh[pt];
		n%=huh[pt];
		pt--;
	}
	cout<<"137";
	FOR(i, 2, N){
		cout<<'3';
		FOR(j, 1, ile[i]) cout<<'7';
	}
	cout<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	FOR(i, 2, N) huh[i]=i*(i-1)/2;
	int tt; cin>>tt;
	FOR(te, 1, tt)
	solve();
	return 0;
}