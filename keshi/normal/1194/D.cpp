#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, t;
bool f;

int main(){
	fast_io;
	cin >> t;
	while(t--){
		cin >> n >> k;
		f = 0;
		if(k % 3 == 0){
			n %= (k + 1);
			if(n % 3 == 0 && n != k){
				f = 1;
			}
		}
		else{
			if(n % 3 == 0){
				f = 1;
			}
		}
		if(f){
			cout << "Bob";
		}
		else{
			cout << "Alice";
		}
		cout << endl;
	}
	return 0;
}