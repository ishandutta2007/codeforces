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
	int n;
	ll k;
	cin >> n >> k;
	vl a(n);
	cin >> a;
	sort(all(a));
	vl sum(n + 1);
	partial_sum(all(a), sum.begin() + 1);
	int i = n / 2;
	for(; i < n - 1 && a[i + 1] * (i - n / 2 + 2) - (sum[i + 2] - sum[n / 2]) <= k;){
		i ++;
	}
	int res = a[i];
	k -= a[i] * (i - n / 2 + 1) - (sum[i + 1] - sum[n / 2]);
	res += k / (i - n / 2 + 1);
	cout << res;
	return 0;
}