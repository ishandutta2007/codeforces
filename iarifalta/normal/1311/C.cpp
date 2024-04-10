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
		ll n,m;
		string a;
		cin >> n >> m >> a;
		ll pref[n][26],ans[26];
		for(int i = 0 ; i < 26 ; i++){
			pref[0][i] = ans[i] = 0;
		}
		for(int i = 0 ; i < n ; i++){
			if(i){
				for(int j = 0 ; j < 26 ; j++){
					pref[i][j] = pref[i - 1][j];
				}
			}
			pref[i][a[i] - 'a']++;
		}
		for(int i = 0 ; i < m ; i++){
			ll x;
			cin >> x;
			for(int j = 0 ; j < 26 ; j++)
				ans[j] += pref[x - 1][j];
		}
		for(int i = 0 ; i < 26 ; i++)
			cout << ans[i] + pref[n - 1][i] << " ";
		cout << "\n";
	}
}
/*
Timus : 288471KD
Atcoder : I_LOVE_TROTT
Codeforces : Zhabka
mail : dzhon.snoudin@mail.ru
*/