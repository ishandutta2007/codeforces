#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e9 + 7;
const int MAXN = 2222 + 10;

int n;
ll cnt[MAXN];
char s[MAXN];
ll pw(ll p,ll q){if(!q)return 1; ll r=1; for(;q;q>>=1){if(q&1)r=r*p%MM;p=p*p%MM;}return r;}
ll gao(ll x,ll c,ll d,ll m){return (((pw(10,c)*pw(100-9*x,m)-pw(91-9*x,m))%MM*x%MM*pw(9,MM-2)%MM)+MM)%MM;}
	
int main(){
	scanf("%s", s + 1);
	n = strlen(s + 1);
	ll ans = 0;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < 10; j++) cnt[j] = 0;
		for (int j = 1; j < i; j++) cnt[s[j] - '0']++;
		for (int k = 0; k < s[i] - '0' + (i == n); k++){
			cnt[k]++;
			int nn = n - i, les = 0;
			for (int j = 0; j < 10; j++){
				ans = (ans + gao(j, cnt[j], les, nn) * pw(10, i - les - cnt[j])) % MM;
				les += cnt[j];
			}
			cnt[k]--;
		}
	}
	printf("%lld\n", (ans % MM + MM) % MM);
	return 0;
}