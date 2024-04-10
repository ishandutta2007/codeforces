#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAXN = 300010;

ll fwc[MAXN]; //quanti sono
ll fw[MAXN]; //somma
bool p[MAXN]; //c'

void up(ll k){
	for(ll i = k; i < MAXN; i+= i&-i)fwc[i]++;
	for(ll i = k; i < MAXN; i+= i&-i)fw[i]+=k;
}

ll qc(ll p){
	ll r = 0;
	for(;p;p-=p&-p)r += fwc[p];
	return r;
}

ll q(ll p){
	ll r = 0;
	for(;p;p-=p&-p)r += fw[p];
	return r;
}

ll rq(ll l, ll r){
	return q(r-1)-q(l-1);
}

ll rqc(ll l, ll r){
	return qc(r-1)-qc(l-1);
}



void solve(){
	ll N; cin >> N;
	ll a;
	ll ans = 0;
	while(N--){
		cin >> a;
		// pi piccoli di lui mod lui
		ans += q(a);
		// lui mod pi grandi di lui
		ans += a*rqc(a,MAXN);
		// pi grandi mod lui
		ans += rq(a,MAXN);
		for(ll i = 1; i*a < MAXN; i++){
			ans -= a*rqc(i*a,MAXN);
		}
		//lui mod pi piccoli di lui
		ll sq = 0;
		while(sq*sq < a)sq++;
		for(ll i = 1; i < sq; i++)if(p[i])ans += a%i;
		ans += a*rqc(sq,a);
		for(ll i = 1; i <= sq; i++){
			ans -= rq(sq,max(sq,(a+i)/i));
		}
		p[a] = 1;
		up(a);
		cout << ans << endl;
	}
	return;
}

int main(){
	solve();
}