#include <bits/stdc++.h>
#define pb push_back
#define ll unsigned long long
#define si short int
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pill pair<ll,ll>
#define f first
#define s second

using namespace std;

const ll N = 64;
const ll big = 1e18;
const ll block = 100;
const ll mod = 1e6;

ll u;
ll v;

ll up[N];

int main() {
    speed;
    cin >> u >> v;
    ll n = v - u;
    if(v < u || n % 2){
    	cout << -1;
    	return 0;
	}
	if(v == 0 && v == u){
		cout << 0 ;
		return 0;
	}
	if(v == u){
		cout << 1 << "\n" << u;
		return 0;
	}
    if(((n / 2) & u) == 0){
    	u += n / 2;
    	cout << 2 << "\n" << u << ' '<< n / 2;
	}
	else{
		cout << 3 << "\n" << u << " " << n / 2 << ' ' << n / 2 << '\n';
	}
}

/*
	Code written by
	Codeforces : I_Love_Trott
	mail : dzhon.snoudin@mail.ru
*/