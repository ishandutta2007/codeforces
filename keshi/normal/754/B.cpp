//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

string s[4];

bool check(){
	for(int i = 0; i < 4; i++){
		if(s[i][0] == 'x' && s[i][1] == 'x' && s[i][2] == 'x') return 1;
		if(s[i][3] == 'x' && s[i][1] == 'x' && s[i][2] == 'x') return 1;
	}
	for(int i = 0; i < 4; i++){
		if(s[0][i] == 'x' && s[1][i] == 'x' && s[2][i] == 'x') return 1;
		if(s[3][i] == 'x' && s[1][i] == 'x' && s[2][i] == 'x') return 1;
	}
	if(s[0][0] == 'x' && s[1][1] == 'x' && s[2][2] == 'x') return 1;
	if(s[3][3] == 'x' && s[1][1] == 'x' && s[2][2] == 'x') return 1;
	if(s[0][1] == 'x' && s[1][2] == 'x' && s[2][3] == 'x') return 1;
	if(s[1][0] == 'x' && s[2][1] == 'x' && s[3][2] == 'x') return 1;
	if(s[3][0] == 'x' && s[2][1] == 'x' && s[1][2] == 'x') return 1;
	if(s[0][3] == 'x' && s[2][1] == 'x' && s[1][2] == 'x') return 1;
	if(s[2][0] == 'x' && s[1][1] == 'x' && s[0][2] == 'x') return 1;
	if(s[3][1] == 'x' && s[2][2] == 'x' && s[1][3] == 'x') return 1;
	return 0;
}

int main(){
	fast_io;
	
	for(int i = 0; i < 4; i++){
		cin >> s[i];
	}
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(s[i][j] == '.'){
				s[i][j] = 'x';
				if(check()){
					cout << "YES\n";
					return 0;
				}
				s[i][j] = '.';
			}
		}
	}
	cout << "NO\n";
	
	return 0;
}