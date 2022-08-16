#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define sd(x) scanf("%d", &(x))
#define vll vector<ll>
#define pb push_back
const int N = 5e5 +10;
char s[N];
ll pref1[N], pref2[N];
int main(){
	int a, b, T, n;
	sd(n), sd(a), sd(b), sd(T);
	int ans = 0; ll pref = 0;
	scanf("%s", s);
	for(int i = 1; i <= n; i++){
		pref += (s[i - 1] == 'w') ? b + 1 : 1;
		pref1[i] = pref;
		if(pref1[i] <= T) ans = i;
		pref += a;
	}
	pref2[1] = pref1[1];
	pref = pref2[1] + a;
	for(int i = 2; i <= n; i++){
		pref += (s[n + 1 - i] == 'w') ? b + 1 : 1;
		pref2[i] = pref;
		if(pref2[i] <= T) ans = max(ans, i);
		pref += a;
	}
	if(ans == n){
		printf("%d\n", n);
		return 0;
	}
	for(int i = 1; i <= n; i++){
		ll k = T - ((i - 1) * 1ll * a + pref1[i] - pref1[1]);
		int ind = upper_bound(pref2 + 1, pref2 + n + 1, k) - (pref2 + 1);
		if(ind != 0) ans = max(ans, i + ind - 1);
		k = T - ((i - 1) * 1ll * a + pref2[i] - pref2[1]);
		ind = upper_bound(pref1 + 1, pref1 + n + 1, k) - (pref1 + 1);
		if(ind != 0) ans = max(ans, i + ind - 1);
	}
	// for(int i = 1; i <= n; i++) cerr << pref1[i] << " " << pref2[i] << endl;
	printf("%d\n", ans);
	return 0;
}