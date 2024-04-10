//In the name of GOD
//Hello Yellow
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll t, r, c;

bool f[maxn], h[maxn], fp[maxn], hp[maxn], e, o, d;

string s[maxn];

int main(){
	fast_io;
	
	cin >> t;
	
	while(t--){
		cin >> r >> c;
		e = 0;
		o = 0;
		d = 1;
		for(ll i = 0; i < r; i++){
			cin >> s[i];
			f[i] = 1;
			fp[i] = 0;
			for(ll j = 0; j < c; j++){
				if(s[i][j] == 'P'){
					f[i] = 0;
					d = 0;
				}
				else{
					fp[i] = 1;
					e = 1;
				}
			}
			if(f[i]) o = 1;
		}
		for(ll j = 0; j < c; j++){
			h[j] = 1;
			hp[j] = 0;
			for(ll i = 0; i < r; i++){
				if(s[i][j] == 'P'){
					h[j] = 0;
				}
				else{
					hp[j] = 1;
				}
			}
			if(h[j]) o = 1;
		}
		if(!e){
			cout << "MORTAL\n";
			continue;
		}
		if(d){
			cout << "0\n";
			continue;
		}
		if(f[0] || f[r - 1] || h[0] || h[c - 1]){
			cout << "1\n";
			continue;
		}
		if(o || s[0][0] == 'A' || s[0][c - 1] == 'A' || s[r - 1][0] == 'A' || s[r - 1][c - 1] == 'A'){
			cout << "2\n";
			continue;
		}
		if(fp[0] || fp[r - 1] || hp[0] || hp[c - 1]){
			cout << "3\n";
			continue;
		}
		cout << "4\n";
	}
	
	return 0;
}