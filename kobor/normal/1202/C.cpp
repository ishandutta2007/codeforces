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

string s;
vi sw, ad;
int wtab[N], atab[N];
int wmax, wmin, amax, amin, pier1, pier2, las1, las2;
bool wda, ada;

ll licz(){
	ll ret=(ll)(wmax-wmin+1)*(amax-amin+1);
	if(wda) ret=min(ret, (ll)(wmax-wmin)*(amax-amin+1));
	if(ada) ret=min(ret, (ll)(wmax-wmin+1)*(amax-amin));
	return ret;
}

void solve(){
	cin>>s;
	FOR(i, 0, SIZE(s)-1){
		if(s[i]=='W' || s[i]=='S') sw.pb((s[i]=='W'?1:-1));
		else ad.pb((s[i]=='A'?1:-1));
	}
	FOR(i, 0, SIZE(sw)-1) wtab[i+1]=wtab[i]+sw[i];
	FOR(i, 0, SIZE(ad)-1) atab[i+1]=atab[i]+ad[i];

		wmax=*max_element(wtab, wtab+SIZE(sw)+1);
		wmin=*min_element(wtab, wtab+SIZE(sw)+1);
		pier1=pier2=inf;
		las1=las2=0;
		FOR(i, 0, SIZE(sw)){
			if(wtab[i]==wmax){
				pier1=min(pier1, i);
				las1=i;
			}
			if(wtab[i]==wmin){
				pier2=min(pier2, i);
				las2=i;
			}
		}

		if(SIZE(sw)<=1) wda=0;
		else wda=(las2<pier1) || (las1<pier2);

		amax=*max_element(atab, atab+SIZE(ad)+1);
		amin=*min_element(atab, atab+SIZE(ad)+1);
		pier1=pier2=inf;
		las1=las2=0;
		FOR(i, 0, SIZE(ad)){
			if(atab[i]==amax){
				pier1=min(pier1, i);
				las1=i;
			}
			if(atab[i]==amin){
				pier2=min(pier2, i);
				las2=i;
			}
		}
		if(SIZE(ad)<=1) ada=0;
		else ada=(las2<pier1) || (las1<pier2);


	cout<<licz()<<ent;
	sw.clear();
	ad.clear();
	wda=ada=0;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int tt; cin>>tt;
	FOR(te, 1, tt)
	solve();
	return 0;
}