#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define po(x) ll(1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long ll;
typedef long double ld;
const ll BLOCK = 400;
const ll DIM = 100007;
const ll MOD = 1000000007;
const ll MAXN = 10E18;
const ll INF = 10E16;
const ll masksz = po(20);
const ll bufsize = 500;
struct pp {
	ll fi, sc;
	bool const operator < (const pp& b) {
		if (fi == b.fi)return sc < b.sc;
		return fi < b.fi;
	}
	bool const operator > (const pp& b) {
		if (fi == b.fi)return sc > b.sc;
		return fi > b.fi;
	}
	bool const operator == (const pp& b) {
		if (fi == b.fi && sc == b.sc)return 1;
		return 0;
	}
};
bool const operator<(const pp& a, const pp& b) {
	if (a.fi == b.fi)return a.sc < b.sc;
	return a.fi < b.fi;
}
bool const operator>(const pp& a, const pp& b) {
	if (a.fi == b.fi)return a.sc > b.sc;
	return a.fi > b.fi;
}

ll n,A[DIM*2],tree[DIM*8],D[DIM*2],tree2[DIM*4],ans[DIM];
void buildtree(ll t, ll tl, ll tr) {
	if (tl == tr) {
		tree[t] = A[tl];
		return;
	}
	ll tm = (tl + tr) / 2;
	buildtree(t*2 + 1, tl, tm); buildtree(t * 2 + 2, tm + 1, tr);
	tree[t] = min(tree[t * 2 + 1], tree[t * 2 + 2]);
}
ll findmax(ll t, ll tl, ll tr, ll l, ll r) {
	if (l > tr || tl > r)return INF;
    if (l<=tl && tr<=r)return tree[t];
    ll tm  = (tl+tr)/2;
    return min(findmax(t*2+1,tl,tm,l,r),findmax(t*2+2,tm+1,tr,l,r));
}
ll bin(ll x){
    ll l = x,r = x+n;
    while(l<r){
        ll tm = (l+r)/2;
        ll mi = findmax(0,1,n*2,x,tm);
        if (mi<(A[x]/2+A[x]%2))r = tm;
        else l = tm+1;
    }
    if (r==n+x)return INF;
    return r;
}

int main() {
	schnell;
	cin >> n;
	forn(i, n)cin >> A[i];
	forn(i,n)A[i+n] = A[i];
	buildtree(0, 1, n*2);
	forn(i,n){
	    D[i]= bin(i);
	    //cout<<D[i]<<' ';
	}
	//cout<<endl;
	forn(i,n)D[i+n] = D[i]+n;
	ll mi = INF;
    for(ll i = n*2;i>=1;i--){
        mi = min(mi,D[i]);
        if (i<=n)ans[i] = mi;
    }
    forn(i,n){
        if (ans[i]>=INF)cout<<"-1 ";
        else cout<<ans[i]-i<<' ';
    }
	return 0;

}