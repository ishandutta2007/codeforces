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

const int N = 1e5 + 10;
int a[N], b[N], p, n;
inline ld f(ld t){
	ld ret = 0;
	for(int i = 1; i <= n; i++) ret += max(0.0, (a[i] * t - b[i]) / p);
	return t - ret;	
}
const ld eps = 1e-6;
int main(){
	sd(n); sd(p);
	for(int i = 1; i <= n; i++) sd(a[i]), sd(b[i]);
	ld lo = 1e-7, hi = 1e18;
	if(f(hi) >= 0){
		printf("-1");
		return 0;
	}
	// cerr << f(0) << " " << f(1) << " " << f(2) << endl;
	while(abs(lo - hi) >= eps){
		ld mid = (lo + hi) / 2.;
		if(f(mid) >= 0.){
			lo = mid;
		}
		else hi = mid;
	}
	printf("%.10lf\n", lo);
}