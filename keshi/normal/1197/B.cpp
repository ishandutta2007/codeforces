#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 100;
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

ll n, a[MAXN], m, t;
bool f;

int main(){
	fast_io;
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		if(a[i] > m){
			m = a[i];
			t = i;
		}
	}
	f = 1;
	for(ll i = 1; i < t; i++){
		if(a[i] < a[i - 1]){
			f = 0;
			break;
		}
	}
	for(ll i = t + 1; i < n; i++){
		if(a[i] > a[i - 1]){
			f = 0;
			break;
		}
	}
	if(f){
		cout << "YES";
	}
	else{
		cout << "NO";
	}
	return 0;
}