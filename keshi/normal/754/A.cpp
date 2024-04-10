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

int n, a[maxn], s;

int main(){
	fast_io;
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		s += a[i];
	}
	if(s != 0){
		cout << "YES\n1\n1 " << n << "\n";
		return 0;
	}
	for(int i = 0; i < n; i++){
		s -= a[i];
		if(s != 0){
			cout << "YES\n2\n1 " << i + 1 << "\n" << i + 2 << " " << n << "\n";
			return 0;
		}
	}
	cout << "NO\n";
	
	return 0;
}