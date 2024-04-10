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
const int N = 1e6 + 10;
int h[N]; bool hole[N];
int main(){
	int n, m, k, u, v; sd(n), sd(m), sd(k);
	for(int i  = 1; i <= m; i++) sd(h[i]), hole[h[i]] = 1;
	int pos = 1; if(hole[1]){pd(1); return 0;}
	while(k--){
		sd(u); sd(v);
		if(pos == u) pos = v;
		else if(pos == v) pos = u;
		if(hole[pos]){ pd(pos); return 0;}
	}
	pd(pos);
}