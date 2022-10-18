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

bool query(int i, int j){
	string s;
	cout<<"? "<<i<<sp<<j<<endl;
	cin>>s;
	if(s=="<") return 1;
	if(s==">") return 0;
	return i < j;
}

void solve(){
	vi male, duze;
	int mink, maxk, n;
	cin>>n;
	FOR(i, 1, n-1){
		if(query(i, i+1)) male.pb(i), duze.pb(i+1);
		else male.pb(i+1), duze.pb(i);
		i++;
	}
	if(n&1) male.pb(n), duze.pb(n);
	mink=male[0], maxk=duze[0];
	FOR(i, 1, SIZE(male)-1) if(query(male[i], mink)) mink=male[i];
	FOR(i, 1, SIZE(duze)-1) if(query(maxk, duze[i])) maxk=duze[i];
	cout<<"! "<<mink<<sp<<maxk<<endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tt; cin>>tt;
	FOR(te, 1, tt)
	solve();
	return 0;
}