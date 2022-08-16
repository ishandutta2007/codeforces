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
int get_t(int t, int n, int k){
	if(n == 0) return 0;
	return t * (1 + (n - 1) / k);
}
int main(){
	int t, n, k, d;
	cin >> n >> t >> k >> d;
	int t1 = get_t(t, n, k);
	int T = t1;
	for(int i = 1; i <= n; i++) T = min(T, max(d + get_t(t, i, k), get_t(t, n - i, k)));
	cout << (T < t1 ? "YES" : "NO");
	return 0;

}