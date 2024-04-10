#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
const long long MOD = 1e9 + 7;
const long long INF = 1e18;

#define ll long long
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second

int q, c1[26], c2[26], ptr;
string s, t, p;
bool f;

int main(){
	fast_io;
	cin >> q;
	while(q--){
		fill(c1, c1 + 26, 0);
		fill(c2, c2 + 26, 0);
		cin >> s >> t >> p;
		ptr = 0;
		f = 1;
		for(int i = 0; i < t.size(); i++){
			if(ptr < s.size() && t[i] == s[ptr]){
				ptr++;
			}
			else{
				c1[t[i] - 'a']++;
			}
		}
		if(ptr < s.size()){
			f = 0;
		}
		for(int i = 0; i < p.size(); i++){
			c2[p[i] - 'a']++;
		}
		for(int i = 0; i < 26; i++){
			if(c1[i] > c2[i]){
				f = 0;
				break;
			}
		}
		if(f){
			cout << "Yes";
		}
		else{
			cout << "No";
		}
		cout << endl;
	}
	return 0;
}