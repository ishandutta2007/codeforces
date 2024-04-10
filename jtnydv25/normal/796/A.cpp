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
#define vll vector<ll >
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define print(s) cerr<<#s<<" : ";for(auto i:(s))cerr<<i<<" ";cerr<<"\n";
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define endl "\n"
const int inf = 1e9;
int main(){
	int t = 1, n, m, k;
	// sd(t);
	while(t--){
		sd(n); sd(m); sd(k);
		int ans = inf, x;
		for(int i = 1; i <= n; i++){
			sd(x);
			if(x && x <= k) ans = min(ans, 10 * abs(i - m));
		}
		pd(ans);
	}
}