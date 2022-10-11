//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const ll maxg = 100;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

int n, f, p[maxn], g[maxn];
bitset<maxn> b, gg[maxg];

int main(){
	fast_io;
	
	for(int i = 2; i < maxn; i++){
		if(p[i]){
			if(p[i / p[i]] == 0) b[i] = 1;
			continue;
		}
		b[i] = 1;
		for(ll j = 1ll * i * i; j < maxn; j += i){
			p[j] = i;
		}
	}
	
	cin >> n >> f;
	b[f] = 0;
	for(int i = 0; i < maxn; i++){
		while(gg[g[i]][i]){
			g[i]++;
		}
		gg[g[i]] |= (b << i);
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		int a, b, c;
		cin >> a >> b >> c;
		ans ^= g[b - a - 1];
		ans ^= g[c - b - 1];
	}
	if(ans){
		cout << "Alice\nBob";
	}
	else cout << "Bob\nAlice";
	
	return 0;
}