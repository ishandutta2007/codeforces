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
const int N = 1e5 + 10; int A[N];
int get_cnt(int r){
	if(r & 1){ return (r >> 1) + 2;}
	return r >> 1;
}
int main(){
	int t = 1, n;
	// sd(t);
	while(t--){
		sd(n);
		int g = 0, s = 0;
		for(int i = 1; i <= n; i++){
			sd(A[i]);
			g = __gcd(g, A[i]);
			s += A[i];
			s %= 2;
		}
		if(g == 0 || g > 1){
			printf("YES\n");
			printf("0\n");
			return 0;
		}
		int i = 1, ans = 0;
		while(i <= n){
			int s = i;
			while(i <= n && (A[i] & 1)) i++;
			ans += get_cnt(i - s);
			while(i <= n && (A[i] % 2 == 0)) i++;
		}
		printf("YES\n");
		printf("%d\n", ans);
	}
}