//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll k, a, b, c, t;
string s;
bool f;

int main(){
	fast_io;
	f = 0;
	while(!f){
		cout << "next 0\n";
		cout.flush();
		a++;
		cin >> k;
		for(ll i = 0; i < k; i++){
			cin >> s;
			if(s == "01" || s == "10") f = 1;
		}
		if(f) break;
		cout << "next 0 1\n";
		cout.flush();
		a++;
		b++;
		cin >> k;
		for(ll i = 0; i < k; i++){
			cin >> s;
			if(s == "01" || s == "10") f = 1;
		}
	}
	f = 0;
	while(!f){
		cout << "next 0\n";
		cout.flush();
		c++;
		cin >> k;
		for(ll i = 0; i < k; i++){
			cin >> s;
			if(s == "01" || s == "10") f = 1;
		}
	}
	if(b + b == a) t = b;
	else{
		for(ll i = 1000; i > 0; i--){
			if(i + c - i % c == b + 1) t = i;
		}
	}
	b = 0;
	f = 1;
	while(f){
		cout << "next";
		if(a % c != t % c) cout << " 0 1", a++;
		if(b < t) cout << " 2 3 4 5 6 7 8 9", b++;
		cout << '\n';
		cout.flush();
		cin >> k;
		if(a % c == t % c && b >= t){
			if(k == 1) f = 0;
			else t++;
		}
		for(ll i = 0; i < k; i++){
			cin >> s;
		}
	}
	cout << "done\n";
	cout.flush();
	
	return 0;
}