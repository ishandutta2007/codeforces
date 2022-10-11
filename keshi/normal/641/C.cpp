#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

ll n, q, a, p1, p2, p3, e[MAXN], d1, d2;

int main(){
	fast_io;
	cin >> n >> q;
	
	p1 = 0;
	p2 = 1;
	p3 = 2;
	
	while(q--){
		cin >> a;
		if(a == 1){
			cin >> a;
			p1 = (p1 + a + n) % n;
			p2 = (p2 + a + n) % n;
			p3 = (p3 + a + n) % n;
		}
		else{
			if(p1 % 2 == 0){
				p1 = (p1 + 1 + n) % n;
			}
			else{
				p1 = (p1 - 1 + n) % n;
			}
			if(p2 % 2 == 0){
				p2 = (p2 + 1 + n) % n;
			}
			else{
				p2 = (p2 - 1 + n) % n;
			}
			if(p3 % 2 == 0){
				p3 = (p3 + 1 + n) % n;
			}
			else{
				p3 = (p3 - 1 + n) % n;
			}
		}
	}
	
	d1 = p2 - p1;
	d2 = p3 - p1;
	
	for(ll i = 0; i * 2 < n; i++){
		p2 = (p1 + d1 + n) % n;
		e[p1] = i * 2 + 1;
		e[p2] = i * 2 + 2;
		p1 = (p1 + d2 + n) % n;
	}
	
	for(ll i = 0; i < n; i++){
		cout << e[i] << ' ';
	}
	
	return 0;
}