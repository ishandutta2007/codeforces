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
int x[N];
int main(){
	int t = 1, n, a, b, c;
	// sd(t);
	while(t--){
		sd(a); sd(b); sd(c);
		sd(n);
		rep(i, 1, n + 1) sd(x[i]);
		sort(x + 1, x + n + 1);
		printf("%d\n", (int)(upper_bound(x + 1, x + n + 1, c - 1) - upper_bound(x + 1, x + n + 1, b)));
	}
}