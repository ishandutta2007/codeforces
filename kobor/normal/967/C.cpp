//Krzysztof Boryczka
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<PII> VPII;

const LD EPS=10e-9;
const int MOD=1000000007;
const int PMOD1=606574021;
const int PMOD2=606574027;
const int INF=1000000009;
const LL LLINF=10000000000000009;

#define FOR(i, b, e) for(int i=b; i<=e; i++)
#define FORD(i, b, e) for(int i=b; i>=e; i--)
#define SIZE(x) ((int)(x).size())

#define PB push_back
#define MP make_pair
#define ST first
#define ND second

//END OF TEMPLATE

set<LL> l, e;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	LL n, m, ln, en, x1, y1, x2, y2, ll, lr, el, er, wyn1, wyn2, wyn3, wyn4, q, v, pom, wyn5;
	cin>>n>>m>>ln>>en>>v;
	FOR(i, 1, ln){
		cin>>pom;
		l.insert(pom);
	}
	FOR(i, 1, en){
		cin>>pom;
		e.insert(pom);
	}
	l.insert(LLINF);
	e.insert(LLINF);
	l.insert(-LLINF);
	e.insert(-LLINF);
	cin>>q;
	FOR(te, 1, q){
		cin>>x1>>y1>>x2>>y2;
		ll=*(prev(l.lower_bound(y1)));
		lr=*(l.lower_bound(y1));
		el=*(prev(e.lower_bound(y1)));
		er=*(e.lower_bound(y1));
		wyn1=abs(y1-ll)+abs(x1-x2)+abs(ll-y2);
		wyn2=abs(y1-lr)+abs(x1-x2)+abs(lr-y2);
		wyn3=abs(y1-el)+abs((x1-x2)/v)+abs(el-y2);
		wyn4=abs(y1-er)+abs((x1-x2)/v)+abs(er-y2);
		wyn5=LLINF;
		//cout<<ll<<' '<<lr<<' '<<el<<' '<<er<<' '<<'\n';
		if(x1==x2){
			wyn5=abs(y1-y2);
		}
		if(((x1-x2)%v+v)%v!=0){
			wyn3++;
			wyn4++;
		}
		cout<<min(wyn1, min(wyn2, min(wyn3, min(wyn4, wyn5))))<<'\n';
	}
	return 0;
}