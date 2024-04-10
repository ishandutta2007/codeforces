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
		ll n;
		cin >> n;
		ll ans[2 * n + 1];
		bool us[2 * n + 1];
		for(int i = 1 ; i <= 2 * n ; i++)
			us[i] = 0;
		for(int i = 0 ; i < n ; i++)
			cin >> ans[i * 2],us[ans[i * 2]] = 1;
		bool answer = 1;
		for(int i = 0 ; i < n ; i++){
			ll x = ans[i * 2];
			bool kek = 0;
			for(int j = x ; j <= 2 * n ; j++)
				if(!us[j]){
					us[j] = 1;
					ans[i * 2 + 1] = j;
					kek = 1;
					break;
				}
			answer &= kek;
		}
		if(answer)
			for(int i = 0 ; i < n; i++)
				cout << ans[2 * i] << " " << ans[2 * i + 1] << " ";
		else
			cout << -1;
		cout << "\n";
	}
}
/*
Timus : 288471KD
Atcoder : I_LOVE_TROTT
Codeforces : Zhabka
mail : dzhon.snoudin@mail.ru
*/