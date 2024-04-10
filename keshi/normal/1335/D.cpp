//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 10;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll t, a[maxn][maxn];

char c;

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		for(ll i = 0; i < 9; i++){
			for(ll j = 0; j < 9; j++){
				cin >> c;
				a[i][j] = (c - '1');
			}
		}
		a[0][0]++;
		a[1][3]++;
		a[2][6]++;
		a[3][1]++;
		a[4][4]++;
		a[5][7]++;
		a[6][2]++;
		a[7][5]++;
		a[8][8]++;
		for(ll i = 0; i < 9; i++){
			for(ll j = 0; j < 9; j++){
				cout << (a[i][j] % 9) + 1;
			}
			cout << '\n';
		}
	}
	
	return 0;
}