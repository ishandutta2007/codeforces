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

const int N=2e5+5;

vi ziomy[N];
int konc;

int znajdz(int val){
	int l=0, r=konc+1, mid;
	while(l+1<r){
		mid=(l+r)/2;
		if(ziomy[mid].back()>val) l=mid;
		else r=mid;
	}
	return r;
}

void solve(){
	int n, a;
	cin>>n;
	FOR(i, 1, n){
		cin>>a;
		int kt=znajdz(a);
		if(kt>konc) konc++;
		ziomy[kt].pb(a);
	}
	FOR(i, 1, konc){
		for(auto &x: ziomy[i]) cout<<x<<sp;
		cout<<ent;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}