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
		cin >> n >> m;
		ll arr[n],x[n],b[m];
		bool can[n] ;
		for(int i = 1 ; i <= n; i++)
			cin >> arr[i];
		for(int i = 1 ; i <= m ; i++)
			cin >> b[i];
		bool ans = 0;
		sort(b + 1, b + m + 1);
		for(int i = 1; i <= n ; i++){
			for(int j = 1 ; j <= m ; j++){
				if(arr[b[j]] > arr[b[j] + 1]){
					swap(arr[b[j]],arr[b[j] + 1]);
				}
			}
		}
		for (int i = 2; i <= n; ++i)
			if (arr[i] < arr[i - 1])
				ans = 1;
		if(ans)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}
/*
Timus : 288471KD
Atcoder : I_LOVE_TROTT
Codeforces : Zhabka
mail : dzhon.snoudin@mail.ru
*/