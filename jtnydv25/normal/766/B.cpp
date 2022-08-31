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
const int N = 1e5+10;
int L[N];
int main(){
	int t = 1,n;
	// sd(t);
	while(t--){
		sd(n);
		rep(i,0,n)sd(L[i]);
		sort(L,L+n);
		string ans = "NO";
		for(int i = 0;i<=n-3;i++){
			// cerr<<L[i]<<" "<<L[i+1]<<" "<<L[i+2]<<endl;
			if(L[i]+L[i+1]>L[i+2]) ans = "YES";
		}
		cout<<ans;
	}
}