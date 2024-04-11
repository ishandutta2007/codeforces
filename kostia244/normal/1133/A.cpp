//#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 100003;
using ld = long double;
int get() {
	string t;
	cin >> t;
	return stoi(t.substr(0, 2))*60+ stoi(t.substr(3, 2));
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int a, b;
	a=get();
	b=get();
	a+=b;
	a/=2;
	string x = to_string((a/60));
	if(x.size()<2) x = "0"+x;
	string y = to_string((a%60));
	if(y.size()<2) y = "0"+y;
	cout << x << ":" << y;
}