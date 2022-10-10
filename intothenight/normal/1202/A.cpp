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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	while(tt --){
		string x, y;
		cin >> x >> y;
		reverse(all(x)), reverse(all(y));
		int p;
		for(p = 0; p < sz(y); p ++){
			if(y[p] == '1'){
				break;
			}
		}
		int k;
		for(k = 0; ; k ++){
			if(x[p + k] == '1'){
				break;
			}
		}
		cout << k << "\n";
	}
	return 0;
}