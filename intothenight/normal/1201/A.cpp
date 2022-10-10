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
	int n, m;
	cin >> n >> m;
	vector<string> ans(n);
	cin >> ans;
	vector<vi> cnt(m, vi(5));
	for(auto v: ans){
		for(int i = 0; i < m; i ++){
			cnt[i][v[i] - 'A'] ++;
		}
	}
	vi score(m);
	cin >> score;
	ll res = 0;
	for(int i = 0; i < m; i ++){
		res += score[i] * *max_element(all(cnt[i]));
	}
	cout << res;
	return 0;
}