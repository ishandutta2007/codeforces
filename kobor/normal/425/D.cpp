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

const int N=1e5+5;

int n, a, b, ans;
vi xy[N], yx[N];
vii pnt;

bool jest(ii pkt){
	return pnt[lower_bound(pnt.begin(), pnt.end(), pkt)-pnt.begin()]==pkt;
}

bool checkx(ii pkt1, ii pkt2){
	int bok=pkt2.nd-pkt1.nd;
	// cout<<pkt1.st<<sp<<pkt1.nd<<sp<<pkt2.st<<sp<<pkt2.nd<<sp<<(jest({pkt1.st+bok, pkt1.nd})&&jest({pkt2.st+bok, pkt2.nd}))<<ent;
	return jest({pkt1.st+bok, pkt1.nd})&&jest({pkt2.st+bok, pkt2.nd});
}

bool checky(ii pkt1, ii pkt2){
	int bok=pkt2.st-pkt1.st;
	// cout<<pkt1.st<<sp<<pkt1.nd<<sp<<pkt2.st<<sp<<pkt2.nd<<sp<<(jest({pkt1.st, pkt1.nd+bok})&&jest({pkt2.st, pkt2.nd+bok}))<<ent;
	return jest({pkt1.st, pkt1.nd+bok})&&jest({pkt2.st, pkt2.nd+bok});
}

void solve(){
	cin>>n;
	FOR(i, 1, n){
		cin>>a>>b;
		xy[a].pb(b);
		yx[b].pb(a);
		pnt.pb({a, b});
	}
	pnt.pb({inf, inf});
	sort(pnt.begin(), pnt.end());
	FOR(i, 0, N-1){
		sort(xy[i].begin(), xy[i].end());
		sort(yx[i].begin(), yx[i].end());
	}
	for(auto &cor: pnt){
		if(cor==make_pair(inf, inf)) continue;
		// cout<<"punkt: "<<cor.st<<sp<<cor.nd<<ent;
		if(SIZE(xy[cor.st])<SIZE(yx[cor.nd])){
			for(int y=lower_bound(xy[cor.st].begin(), xy[cor.st].end(), cor.nd)-xy[cor.st].begin()+1; y<SIZE(xy[cor.st]); y++){
				ans+=checkx(cor, {cor.st, xy[cor.st][y]});
			}
		}
		else{
			for(int y=lower_bound(yx[cor.nd].begin(), yx[cor.nd].end(), cor.st)-yx[cor.nd].begin()+1; y<SIZE(yx[cor.nd]); y++){
				ans+=checky(cor, {yx[cor.nd][y], cor.nd});
			}
		}
	}
	cout<<ans<<ent;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}