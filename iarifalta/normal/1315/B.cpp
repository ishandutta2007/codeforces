#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define f first
//#define s second
#define pill pair<ll,ll>
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const ll N = 3e3;
ll t;

int main() {
	speed;
	cin >> t;
	while(t--){
		ll a,b,p;
		string s;
		cin >> a >> b >> p >> s;
		reverse(s.begin() , s.end());
		ll n = s.size();
		ll dp[n];
		for(int i = 0 ; i < n ; i++)
			dp[i] = INT_MAX;
		dp[0] = 0;
		for(int i = 1 ; i < n ; i++){
			if(s[i] == s[i - 1])
				dp[i] = dp[i - 1] + (i == 1 ? s[0] == 'A' ? a : b : 0);
			else
				dp[i] = dp[i - 1] + (s[i] - 'A'? b : a );
		}
		ll ans = n;
		for(int i = n - 1 ; i >= 0 ; i--){
			if(p >= dp[i])
				ans = min(ans,n - i);
		}
		cout << ans << "\n";
	}
}
/*
3 2 8
AABBBBAABB

Timus : 288471KD
Atcoder : I_LOVE_TROTT
Codeforces : Zhabka
mail : dzhon.snoudin@mail.ru
*/