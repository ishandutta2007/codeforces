#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int MAXN = 100005;

int main(){
	int t; cin  >> t;
	while(t--){
		string s, t;
		cin >> s; cin >> s;
		t = s;
		sort(all(t));
		int cnt = 0;
		for(int i = 0; i < sz(s); i++){
			if(s[i] != t[i]) cnt++;
		}
		cout << cnt << endl;
	}
}