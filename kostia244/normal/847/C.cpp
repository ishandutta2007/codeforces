#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
const int D = 30, maxn = 90e5;
ll n, k,z=1,op = 1;
string s="(";
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 0; op < n; i++) {
		if(z<=k) {
			s+='(';
			k -= z++;
			op++;
		} else {
			s += ')';
			z--;
		}
	}
	if(k) return cout << "Impossible", 0;
	while(z--)
		s += ')';
	cout << s;
}