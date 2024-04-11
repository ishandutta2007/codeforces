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

const int N=1e5+5;
const int ST=100;

int a[N], b[N];
int n, d, xx, maks;
vi jedyn;
set<ii> ziomki;

int getNextX(){
	xx=((ll)xx*37+10007)%(1000000007);
	return xx;
}

void init(){
	FOR(i, 0, n-1) a[i]=i+1;
	FOR(i, 0, n-1) swap(a[i], a[getNextX()%(i+1)]);
	FOR(i, 0, n-1) b[i]=(i<d);
	FOR(i, 0, n-1) swap(b[i], b[getNextX()%(i+1)]);
}

void solve(){
	cin>>n>>d>>xx;
	init();
	if(d<=ST){
		FOR(i, 0, n-1){
			if(b[i]) jedyn.pb(i);
			maks=0;
			for(auto &x: jedyn) maks=max(maks, a[i-x]);
			cout<<maks<<ent;
		}
	}
	else{
		bool gituwa;
		FOR(i, 0, n-1){
			ziomki.insert({-a[i], i});
			gituwa=0;
			for(auto &x: ziomki) if(b[i-x.nd]){
				cout<<-x.st<<ent;
				gituwa=1;
				break;
			}
			if(!gituwa) cout<<0<<ent;
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solve();
	return 0;
}