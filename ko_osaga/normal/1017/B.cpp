#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using pi = pair<lint, int>;

const int MAXN = 3005;
int cnt[2][2];

string s, t;

int main(){
	int n; cin >> n;
	cin >> s >> t;
	for(int i=0; i<n; i++){
		cnt[s[i] & 1][t[i] & 1]++;
	}
	lint ans = 0;
	for(int i=0; i<4; i++){
		for(int j=0; j<i; j++){
			int l = cnt[i/2][i%2];
			int r = cnt[j/2][j%2];
			int C = (i%2) * 2 + (j%2);
			int A = (i/2) * 2 + (j/2);
			int B = (j/2) * 2 + (i/2);
			if((A|C) != (B|C)) ans += 1ll * l * r;
		}
	}
	cout << ans << endl;
}