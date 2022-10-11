//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 5e5 + 100;
const ll level = 25;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, b, l, r, a[maxn], cnt[level];

vector<ll> fen[maxn];

void upd(ll f, ll x){
	for(; x < fen[f].size(); x += x & -x){
		fen[f][x]++;
	}
	return;
}

ll get(ll f, ll x){
	ll s = 0;
	for(; x > 0; x -= x & -x){
		s += fen[f][x];
	}
	return s;
}

int main(){
	fast_io;
	
	for(ll i = 0; i < level; i++){
		fen[i].resize((1 << (i + 1)) + 10);
		fill(fen[i].begin(), fen[i].end(), 0);
	}
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		for(ll j = 0; j < level; j++){
			b = a[i] % (1 << (j + 1));
			l = ((1 << j) - b + (1 << (j + 1))) % (1 << (j + 1));
			r = ((1 << (j + 1)) - 1 - b + (1 << (j + 1))) % (1 << (j + 1));
			cnt[j] += get(j, r + 1) - get(j, l);
			if(l > r) cnt[j] += i;
			upd(j, b + 1);
		}
	}
	
	b = 0;
	
	for(ll i = 0; i < level; i++){
		if(cnt[i] % 2) b += (1 << i);
	}
	
	cout << b;
	
	return 0;
}