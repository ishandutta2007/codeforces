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

int n;
ll x, y, a;

bool zyje(ll wh){
	return wh/y+wh/x<a;
}

void odp(){
	ll l, r, mid;
	l=0; r=INF;
	while(l+1<r){
		mid=(l+r)/2;
		if(zyje(mid)) l=mid;
		else r=mid;
	}
	if(r%y==0){
		if(r%x==0) cout<<"Both";
		else cout<<"Vanya";
	}
	else cout<<"Vova";
	cout<<ent;
}

void solve(){
	cin>>n>>x>>y;
	FOR(i, 1, n){
		cin>>a;
		odp();
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}