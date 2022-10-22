#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define si short int
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pill pair<ll,ll>
#define f first
#define s second
#define pilc pair<ll,char>
#define all(a) (a).begin(),(a).end()
#define rep(s,e,step) for(int i = (s); i < (e) ; i += step)
#define vrep(s,e,step) for(int j = (s); j < (e) ; j += step)
#define ex exit(0)
#define sz(a) (a).size()
 
 
using namespace std;
 
const ll N = 1504;
const ll big = 1e18;
const ll block = 800;
const ll mod = 1e6;

string a;
ll ans = 6;

ll sum[2];

void rec(ll cur, ll izm) {
	if(cur == 6) {
		if(sum[0] == sum[1])
			ans = min(izm, ans);
		return;
	}
	for(int i = 0 ; i < 10 ; i++) {
		sum[cur / 3] += i;
		rec(cur + 1, izm + (a[cur] - '0' != i));
		sum[cur / 3] -= i;
	}
}
 
int main() {
	speed;
	cin >> a;
	rec(0, 0);
	cout << ans;
 
}
 
/*
	Code written by
	Codeforces : I_Love_Trott
	mail : dzhon.snoudin@mail.ru
*/