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

ll a00, a01, a10, a11;
string ans;

bool gut(){
	ll x00=0, x01=0, x10=0, x11=0, z=0, j=0;
	for(auto &x: ans){
		if(x=='0'){
			x00+=z;
			x10+=j;
			z++;
		}
		else{
			x01+=z;
			x11+=j;
			j++;
		}
	}
	return x00 == a00 && x01 == a01 && x10 == a10 && x11 == a11;
}


void check(ll zer, ll jed){
	if(zer*(zer-1) != a00*2) return;
	if(jed*(jed-1) != a11*2) return;
	ans.clear();
	if(zer == 0) FOR(i, 1, jed) ans.pb('1');
	else if(jed == 0) FOR(i, 1, zer) ans.pb('0');
	else{
		ll akt=zer*jed;
		while(1){
			if(akt-zer > a01){
				ans.pb('1');
				jed--;
				akt -= zer;
				continue;
			}
			ll ile = akt-a01;
			if(jed <= 0 || ile < 0) return;
			FOR(i, 1, zer-ile) ans.pb('0');
			ans.pb('1');
			FOR(i, zer-ile+1, zer) ans.pb('0');
			FOR(i, 1, jed-1) ans.pb('1');
			break;
		}
	}
	if(gut()){
		cout<<ans<<ent;
		exit(0);
	}
}

ll rob(ll val){
	ll ret=1;
	while(ret*(ret-1) < val*2) ret++;
	return ret;
}

void solve(){
	cin>>a00>>a01>>a10>>a11;
	ll zer=rob(a00);
	ll jed=rob(a11);
	check(0, jed);
	check(zer, 0);
	check(zer, jed);
	cout<<"Impossible"<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	// int tt; cin>>tt;
	// FOR(te, 1, tt)
	solve();
	return 0;
}