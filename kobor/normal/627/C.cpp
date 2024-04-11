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

const int N=2e5+5;

ll n, d, ans;
int m;
ll ost, bak;
ii stacja[N];
deque<ii> fajne;

void solve(){
	cin>>d>>n>>m;
	FOR(i, 1, m) cin>>stacja[i].st>>stacja[i].nd;
	m++;
	stacja[m]={d, 0};
	sort(stacja+1, stacja+m+1);
	ost=0, bak=n;
	FOR(i, 1, m){
		//tankujemy
		ll trzeba=stacja[i].st-ost-bak;
		while(trzeba > 0){
			if(fajne.empty()){
				cout<<-1<<ent;
				return;
			}
			auto gosc = fajne.front();
			ll mogetam = min({n, trzeba, n-(bak-(gosc.st-ost))});
			if(mogetam <= 0){
				fajne.pop_front();
				continue;
			}
			ans += mogetam * gosc.nd;
			bak = bak - (gosc.st - ost) + mogetam;
			ost = gosc.st;
			trzeba=stacja[i].st-ost-bak;
		}
		while(SIZE(fajne) && fajne.back().nd >= stacja[i].nd) fajne.pop_back();
		fajne.pb(stacja[i]);
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