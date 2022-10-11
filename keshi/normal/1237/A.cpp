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

ll n, a, cnt;

double b;

int main(){
	fast_io;
	
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a;
		b = a;
		if(a % 2){
			if(cnt % 2){
				cout << floor(b / 2);
			}
			else{
				cout << floor(b / 2) + 1;
			}
			cnt++;
		}
		else{
			cout << a / 2;
		}
		cout << endl;
	}
	
	return 0;
}