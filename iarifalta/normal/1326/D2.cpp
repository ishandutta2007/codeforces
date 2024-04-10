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
	cin >> t;
	while(t--) {
		string a;
		cin >> a;
		ll n = a.size() - 1;
		string b;
		ll xs = 0;
		bool e = 1;
		for(int i = 0 ; i <= n ; i++){
			if(xs < (n + 1) / 2 && e && a[i] == a[n - i])
				xs++;
			else
				e = 0;
		}
		for(int i = xs ; i <= n - xs ; i++)
			b += a[i];
		ll tl = 0 , tr = -1;
		ll pal[2][2 * n + 1] = {{0} , {0}};
		for(int j = 0 ; j < 2 ; j++)
			for(ll i = 0 ,l = 0,r = -1; i < b.size() ; i++){
				ll k = 0;
				if(i <= r){
					if(j == 0)
						k = min( r - i + 1, pal[j][l + r - i]);
					else
						k = min( r - i + 1, pal[j][l + r - i + 1]);
				}	
				while(i - k - j >= 0 && i + k < b.size() && b[i - k - j] == b[i + k])
					k++;
			
				pal[j][i] = k;
				if(i + k - 1 >= r)
					l = i - k - j + 1,r = i + k - 1;
				ll x = i - k - j + 1;
				if( (x == 0 || i + k - 1 == b.size() - 1) && (tr - tl + 1) <= (i + k - 1 - x + 1)){
					tl = x , tr = i + k - 1;
				}
			}
		ll ans =  0;
		for(int i = 0 ; i < xs ; i++)
			cout << a[i] ;
		for(int i = tl ; i <= tr ; i++)
			cout << b[i] ;
		for(int i = n - xs + 1 ; i <= n ; i++)
			cout << a[i] ;
		cout << '\n';
	}

}

/*
	Code written by
	Codeforces : I_Love_Trott
	mail : dzhon.snoudin@mail.ru
*/