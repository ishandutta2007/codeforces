#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define f first
#define s second
#define pill pair<ll,ll>
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const ll N = 3e3;
ll t;
int main() {
	speed;
	cin >> t;
	while(t--){
		ll a,b;
		cin >> a >> b;
		ll ans = 0;
		if(a > b){
			ll y = (a - b);
			if(y % 2)
				ans = 2;
			else
				ans = 1;
		}
		else if(a < b){
			ll z = (b - a);
			if(z % 2)
				ans = 1;
			else
				ans = 2;
		}
		cout  << ans << "\n";
	}
}
/*
Timus : 288471KD
Atcoder : I_LOVE_TROTT
Codeforces : Zhabka
mail : dzhon.snoudin@mail.ru
*/