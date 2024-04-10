#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define si short int
#define speed ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pill pair<ll,ll>
#define f first
#define s second

using namespace std;

const ll N = 250002;
const ll big = 1e9;
const ll block = 100;
const ll mod = 1e6;

ll t;

int main() {
    speed;
 		ll n;
    	cin >> n;
    	ll a[n] , b[n];
    	for(int i = 0 ; i < n ; i++)
    		cin >> b[i];
    	a[0] = b[0];
    	ll mx = max(0ll, b[0]);
    	cout << a[0] << " ";
		for(int i = 1 ; i < n ; i++){
    		a[i] = b[i] + mx;
    		mx = max(a[i], mx);
    		cout << a[i] << " ";
		}
		
}

/*
	Code written by
	Codeforces : I_Love_Trott
	mail : dzhon.snoudin@mail.ru
*/