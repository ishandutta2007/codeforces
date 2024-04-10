#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define file_io freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

ll a, b, c, d, e, r;
bool f = 1;

int main(){
	fast_io;
	cin >> a;
	r = a;
	d = INF;
	e = INF;
	while(r > 0){
		r = a - b * 7;
		c = r / 4;
		if(r >= 0 && r % 4 == 0){
			if(b + c < d + e){
				d = c;
				e = b;
				f = 0;
			}
			else if(c + b == d + e && b < e){
				d = c;
				e = b;
				f = 0;
			}
		}
		b++;
	}
	if(f){
		cout << -1;
		return 0;
	}
	for(int i = 0; i < d; i++){
		cout << 4;
	}
	for(int i = 0; i < e; i++){
		cout << 7;
	}
	
	return 0;
}