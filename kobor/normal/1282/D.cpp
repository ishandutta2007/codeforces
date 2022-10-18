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

string ans;

void solve(){
	int l, a, b, xd;
	FOR(i, 1, 300) cout<<'a';
	cout<<endl;
	cin>>a;
	if(a==0) return;
	a=300-a;
	FOR(i, 1, 300) cout<<'b';
	cout<<endl;
	cin>>b;
	if(b==0) return;
	b=300-b;
	l=a+b;
	FOR(j, 1, l-1){
		FOR(i, 1, l) cout<<(i==j? 'b' : 'a');
		cout<<endl;
		cin>>xd;
		if(xd==0) return;
		ans+=(xd==b-1 ? 'b' : 'a');
	}
	xd=0;
	for(auto &x: ans) xd+=x=='a';
	ans+=(xd==a ? 'b' : 'a');
	cout<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}