#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	int n;
	cin >> n;
	int x = 1;
	while(s.size() < n)
		s += to_string(x++);
	cout << s[n-1];
}