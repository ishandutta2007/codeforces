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
const ll N = 3e3,inf = INT_MAX;
ll t;
int main() {
	speed;
	cin >> t;
	while(t--){
		ll n,m;
		ll a,b,c;
		cin >> a >> b >> c;
		int mn1 = inf, mn2 = inf , ans = inf, ansa, ansb, ansc;
		for(int i = 1 ; i <= 20000 ; i++){
			mn1 = inf, mn2 = inf;
			for(int j = 1 ; j * j <= i ; j++){
				if(i % j == 0) {
					ll k1 = j;
					ll k2 = i / j;
					if (abs(mn1 - a) > abs(k1 - a)) {
						mn1 = k1;
					}				
					if (abs(mn1 - a) > abs(k2 - a)) {
						mn1 = k2;
					}									
				}
				int x = c / i;
				if (abs(x * i - c) < abs((x + 1) * i - c)) 
						mn2 = x * i;
				else
					mn2 = (x + 1) * i;
				if (ans > (abs(mn1 - a) + abs(i - b) + abs(mn2 - c))) {
					ans = (abs(mn1 - a) + abs(i - b) + abs(mn2 - c));
					ansa = mn1;
					ansb = i;
					ansc = mn2;
				}
			}			
		}
		cout << ans << "\n";
		cout << ansa << " " << ansb << " " << ansc << "\n";
	}
}
/*
Timus : 288471KD
Atcoder : I_LOVE_TROTT
Codeforces : Zhabka
mail : dzhon.snoudin@mail.ru
*/