#include <bits/stdc++.h>
#define eb emplace_back
#define INF (0x3f3f3f3f)
#define INFLL (0x3f3f3f3f3f3f3f3fll)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;

const ll MOD = 1e9 + 7;

ll D[1000005];
ll N, Ans;

int main()
{
	ll i, j, a;
	
	scanf("%lld", &N);
	
	D[0] = 1;
	
	for(ll i = 1; i <= N; i ++){
		scanf("%lld", &a);
		
		ll j;
		
		for(j = 1; j * j <= a; j ++){
			if(a % j == 0){
				D[a / j] = (D[a / j] + D[a / j - 1]) % MOD;
			}
		}
		
		for(j --; j >= 1; j --){
			if(j * j == a) continue;
			if(a % j == 0){
				D[j] = (D[j] + D[j - 1]) % MOD;
			}
		}
	}
	
	for(ll i = 1; i <= (ll) 1e6; i ++){
		Ans = (Ans + D[i]) % MOD;
	}
	
	cout << Ans << endl;
	return 0;
}