#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll lcm(ll a, ll b){
	return a * (b / __gcd(a, b));
}
const int N  = 1e6 + 10;
int freq1[26][N], freq2[26][N];

char x[N], y[N];
int main(){
	ll n, m;
	scanf("%lld %lld", &n, &m);
	scanf("%s", x);
	scanf("%s", y);
	ll lenx = strlen(x), leny = strlen(y);

	ll len = n * lenx;
	ll L = lcm(lenx, leny);
	ll g = __gcd(lenx, leny);
	for(int i = 0; i < lenx; i++) freq1[x[i] - 'a'][i % g]++;
	for(int i = 0; i < leny; i++) freq2[y[i] - 'a'][i % g]++;
	long long ans = L;
	for(int i = 0; i < g; i++){
		for(int j = 0; j < 26; j++) ans -= freq1[j][i] * 1ll * freq2[j][i];
	}
	ans *= (len / L);
	printf("%lld\n", ans);
}