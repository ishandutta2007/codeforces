#include<iostream>
#include<string>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
typedef long long ll;
const ll INF=(ll)1e13+7LL;
int rb,rc,rs,pb,pc,ps,nb,nc,ns;
ll r;
void init(void) {
	string s;
	cin >> s >> nb >> ns >> nc >> pb >> ps >> pc >> r;
	FORE(it,s) {
		if (*it=='B') rb++;
		if (*it=='C') rc++;
		if (*it=='S') rs++;
	}	
}
bool ok(ll x) {
	ll b=x*rb;
	ll c=x*rc;
	ll s=x*rs;
	ll all=max(0LL,b-nb)*pb+max(0LL,c-nc)*pc+max(0LL,s-ns)*ps;
	return (all<=r);
}
void process(void) {
	ll l=0;
	ll r=INF;
	while (true) {
		if (l==r) {
			cout << r;
			return;
		}
		if (r-l==1) {
			if (ok(r)) cout << r; else cout << l;
			return;
		}
		ll m=(l+r)/2;
		if (ok(m)) l=m;
		else r=m-1;
	}
}
int main(void) {
	ios::sync_with_stdio(false);
	init();
	process();
	return 0;
}