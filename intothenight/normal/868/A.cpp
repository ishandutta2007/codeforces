#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string p;
	int n;
	cin >> p >> n;
	vector<string> a(n);
	vector<vi> used(2, vi(26));
	for(auto &s: a){
		cin >> s;
		if(s == p){
			cout << "YES";
			return 0;
		}
		used[0][s[0] - 'a'] = true;
		used[1][s[1] - 'a'] = true;
	}
	if(used[0][p[1] - 'a'] && used[1][p[0] - 'a']){
		cout <<  "YES";
	}
	else{
		cout << "NO";
	}
	return 0;
}