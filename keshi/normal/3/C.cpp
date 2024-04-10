//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, cx, c0;

bool a[10], b[10], A, B;

char s[3][3];

int main(){
	fast_io;
	
	for(ll i = 0; i < 3; i++){
		for(ll j = 0; j < 3; j++){
			cin >> s[i][j];
			if(s[i][j] == 'X'){
				cx++;
			}
			if(s[i][j] == '0'){
				c0++;
			}
		}
	}
	
	fill(a, a + 10, 1);
	fill(b, b + 10, 1);
	
	if(cx - c0 > 1 || cx - c0 < 0){
		cout << "illegal";
		return 0;
	}
	
	for(ll i = 0; i < 3; i++){
		for(ll j = 0; j < 3; j++){
			if(s[i][j] != 'X'){
				a[i] = 0;
			}
			if(s[i][j] != '0'){
				b[i] = 0;
			}
		}
	}
	for(ll i = 0; i < 3; i++){
		for(ll j = 0; j < 3; j++){
			if(s[i][j] != 'X'){
				a[j + 3] = 0;
			}
			if(s[i][j] != '0'){
				b[j + 3] = 0;
			}
		}
	}
	a[6] = (s[0][0] == 'X' && s[1][1] == 'X' && s[2][2] == 'X');
	a[7] = (s[0][2] == 'X' && s[1][1] == 'X' && s[2][0] == 'X');
	b[6] = (s[0][0] == '0' && s[1][1] == '0' && s[2][2] == '0');
	b[7] = (s[0][2] == '0' && s[1][1] == '0' && s[2][0] == '0');
	
	for(ll i = 0; i < 8; i++){
		if(a[i]) A = 1;
		if(b[i]) B = 1;
	}
	if(A && B){
		cout << "illegal";
		return 0;
	}
	if(A){
		if(cx > c0){
			cout << "the first player won";
		}
		else{
			cout << "illegal";
		}
		return 0;
	}
	if(B){
		if(cx == c0){
			cout << "the second player won";
		}
		else{
			cout << "illegal";
		}
		return 0;
	}
	if(cx + c0 == 9){
		cout << "draw";
		return 0;
	}
	if(cx > c0){
		cout << "second";
	}
	else{
		cout << "first";
	}
	
	return 0;
}