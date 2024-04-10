#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"

#define P pair<int, set<int> >

map<P, int> grundy;
inline int mex(set<int> s){
	int j = 0;
	for(int i: s){
		if(i != j) return j;
		j++;
	}
	return j;
}
int g(int n, set<int> s){
	// print(s);
	if(n == 0) return 0;
	if(grundy. find(mp(n,s)) != grundy.end()) return grundy[mp(n,s)];
	set<int> S;
	for(int i = 1;i<=n;i++){
		if(s.find(i) == s.end()){
			set<int> _s = s;
			_s.insert(i);
			S.insert(g(n-i,_s));
		}
	}
	// print(S);
	int ret = mex(S);
	grundy[mp(n,s)] = ret;
	return mex(S);
}
int G[61] = {0, 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 10};
int main(){
	int n,x;
	sd(n);
	int xr = 0;
	rep(i,1,n+1) sd(x), xr^=G[x];
	cout << ((xr != 0)?"NO":"YES");
}