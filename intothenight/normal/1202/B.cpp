#include<bits/stdc++.h>
#include<chrono>
#pragma GCC optimize("Ofast")
using namespace std;
using namespace chrono;
#define all(a) a.begin(), a.end()
#define sz(x) (int(x.size()))
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef vector<string> vs;
template<class T1, class T2>
istream &operator>>(istream &in, pair<T1, T2> &P){
	in >> P.first >> P.second;
	return in;
}
template<class T1, class T2>
ostream &operator<<(ostream &out, pair<T1, T2> &P){
	out << "(" << P.first << ", " << P.second << ")";
	return out;
}
template<class T>
istream &operator>>(istream &in, vector<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<class T>
ostream &operator<<(ostream &out, vector<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}
ll d[10][10][10];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	const ll INF = 9e18;
	for(ll i = 0; i < 10; i ++){
		for(ll j = 0; j < 10; j ++){
			for(ll k = 0; k < 10; k ++){
				d[i][j][k] = INF;
				for(ll l = 0; l <= 10; l ++){
					for(ll m = 0; m <= 10; m ++){
						if((l || m) && (i * l + j * m) % 10 == k){
							d[i][j][k] = min(d[i][j][k], l + m);
						}
					}
				}
				if(d[i][j][k] == INF){
					d[i][j][k] = -1;
				}
			}
		}
	}
	string s;
	cin >> s;
	vector<ll> cnt(10);
	for(ll i = 0; i < sz(s) - 1; i ++){
		cnt[(s[i + 1] - s[i] + 10) % 10] ++;
	}
	for(ll i = 0; i < 10; i ++){
		for(ll j = 0; j < 10; j ++){
			ll sum = 0;
			bool fail = false;
			for(ll k = 0; k < 10; k ++){
				if(cnt[k] && d[i][j][k] == -1){
					cout << -1 << " ";
					fail = true;
					break;
				}
				sum += cnt[k] * max(d[i][j][k] - 1, 0LL);
			}
			if(!fail){
				cout << sum << " ";
			}
		}
		if(i != 9) cout << "\n";
	}
	return 0;
}