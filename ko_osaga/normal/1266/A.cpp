#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
using lint = long long;
using pi = pair<lint, lint>;
const int mod = 1e9 + 7;
const int MAXN = 10005;

int main(){
	int tc; cin >> tc;
	while(tc--){
		string s; cin >> s;
		int sum = 0, cnt[10] = {};
		for(auto &i : s){
			cnt[i-'0']++;
			sum += (i - '0');
		}
		bool good = 0;
		if(sum % 3 == 0 && cnt[0]){
			cnt[0]--;
			for(int j=0; j<10; j+=2){
				if(cnt[j] > 0) good = 1;
			}
		}
		puts(good ? "red" : "cyan");
	}
}