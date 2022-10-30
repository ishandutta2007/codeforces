#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define po(x) ll(1<<x)
#define schnell ios_base::sync_with_stdio(NULL); cin.tie(NULL); cout.tie(NULL)
#define forn(i,n) for(ll i = 1;i<=n;i++)
typedef long long  ll;
typedef long double ld;
#define DIM 500007
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
struct node {
	ll fi, sc, w;
};
ll q, n, k,dp[2][DIM],W[DIM];
vector<pp> A[DIM];
bool mc(pp a,pp b){
    return a.sc-a.fi>b.sc-b.fi;
}
void dfs(ll v,ll par){
    vector<pp> V;
    ll r = 0;
    for(pp to:A[v]){
        if (to.fi==par) continue;
        W[to.fi] =to.sc;
        dfs(to.fi,v);
        if (dp[0][to.fi]>=dp[1][to.fi])r+=dp[0][to.fi];
        else
            V.pb({dp[0][to.fi],dp[1][to.fi]});
    }
    sort(V.begin(),V.end(),mc);
    while(V.size()>k){
        r+=V.back().fi;
        V.pop_back();
    }
    for(pp to:V)r+=to.sc;
    dp[0][v] = r;
    V.clear();
    r = 0;
    for(pp to:A[v]){
        if (to.fi==par) continue;
        //W[to.fi] =to.sc;
        //dfs[to.fi];
        if (dp[0][to.fi]>=dp[1][to.fi])r+=dp[0][to.fi];
        else
            V.pb({dp[0][to.fi],dp[1][to.fi]});
    }
    sort(V.begin(),V.end(),mc);
    //if (v==2)for(pp to:V)cout<<to.fi<<' '<<to.sc<<endl;
    while(V.size()>=k){
        r+=V.back().fi;
        V.pop_back();
    }
    for(pp to:V)r+=to.sc;
    dp[1][v] = r+W[v];
}
int main() {
	schnell;
	cin >> q;
	forn(query, q) {
		cin >> n >> k;
		forn(i,n){
            A[i].clear();
            W[i] = 0;
            dp[0][i]=dp[1][i] =0;
		}
		forn(i, n - 1) {
			ll x,y,w;
			cin>>x>>y>>w;
			A[x].pb({y,w});
			A[y].pb({x,w});
		}
        dfs(1,-1);
        cout<<max(dp[1][1],dp[0][1])<<endl;
	}
	return 0;
}