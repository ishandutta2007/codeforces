#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;

vector<ll> ans;
string s;
void getAns(char c, ll n) {
	for(ll i = 0; i < n - 1; i++)
		if(s[i] != c) {
			ans.push_back(i + 1);
			s[i] = 'W' + 'B' - s[i];
			s[i  + 1] = 'W' + 'B' - s[i + 1];
		}	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin >> n >> s;
	ll wC = 0, bC = 0;
	for(ll i = 0; i < n; i++)
		if(s[i] == 'W') wC++; else bC++;
	if(!(wC % 2)) getAns('B', n);
	else if(!(bC % 2)) getAns('W', n);
	else {
		cout << -1 << endl;
		return 0;
	}
		cout << ans.size() << endl;
		for(ll i : ans) cout << i << " ";
		cout << endl;	
}