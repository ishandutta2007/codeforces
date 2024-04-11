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

int n;
ll pipe, pill, ans;
string s;
deque<int> zer, jed;

void miel(){
	ans=0;
	zer.clear(); jed.clear();
	int cnt=0;
	char co='0';
	for(auto &x: s){
		if(x!=co){
			if(co=='0') zer.pb(cnt);
			else jed.pb(cnt);
			cnt=0;
			co=x;
		}
		cnt++;
	}
	if(co=='0') zer.pb(cnt);
	else jed.pb(cnt);
}

void solve(){
	cin>>n>>pipe>>pill>>s;
	miel();
	if(!SIZE(jed)){
		cout<<(ll)SIZE(s)*(pipe+pill)+pill<<ent;
		return;
	}
	ans=(ll)(zer[0]+1)*(pipe+pill)+pill;
	zer.pop_front();
	while(1){
		ans+=(ll)jed[0]*(pipe+pill*2);
		jed.pop_front();
		if(!SIZE(jed)){
			ans+=(ll)zer[0]*(pipe+pill)+pipe;
			break;
		}
		ans+=min((ll)(zer[0]+1)*(pipe+pill)+pipe, (ll)zer[0]*(pipe+pill*2));
		zer.pop_front();
	}
	cout<<ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tt; cin>>tt;
	FOR(te, 1, tt)
	solve();
	return 0;
}