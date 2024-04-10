#include <bits/stdc++.h>
using namespace std;


typedef long long ll;

const ll maxn = 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll q, n, a, b, cnt[maxn];

int main(){
	fast_io;
	
	cin >> q;
	
	while(q--){
		fill(cnt, cnt + 100, 0);
		cin >> n;
		for(ll i = 0; i < n; i++){
			cin >> a;
			b = 0;
			while(a){
				b++;
				a /= 2;
			}
			cnt[b]++;
		}
		for(ll i = 1; i < 30; i++){
			cnt[i] += cnt[i - 1] / 2;
		}
		if(cnt[12]){
			cout << "YES";
		}
		else{
			cout << "NO";
		}
		cout << endl;
	}
	
	return 0;
}