#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define pb push_back
#define F first
#define S second
#define sd(x) scanf("%d", &(x))
int TRY = 1e6;
int main(){
	int n, m, k;
	sd(n); sd(m); sd(k);
	int mid = k >> 1;
	long long ans = 0;
	int mn = 0, mx = k;
	mn = max(mn, k - m + 1);
	mx = min(mx, n - 1);
	if(mn > mx){
		printf("-1\n"); 
		return 0;
	}
	for(int i = mn; i <= mx && i <= TRY + mn; i++){
		ans = max(ans, (n / (i + 1)) * 1ll * (m / (k - i + 1)));
	}
	for(int i = mx; i >= mn &&  i >= mx - TRY; i--){
		ans = max(ans, (n / (i + 1)) * 1ll * (m / (k - i + 1)));	
	}
	if(ans == 0) ans = -1;
	printf("%lld", ans);
}