#include <bits/stdc++.h>
using namespace std;

const int N = 105;
const char s[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM0123456789";

int c[N];
char b[N][N];

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	int rc = 0;
	for(int i = 0; i < n; i++){
		cin >> b[i];
		for(int j = 0; j < m; j++){
			rc += (b[i][j] == 'R');
		}
	}
	fill(c, c + k, 0);
	for(int i = 0; i < rc; i++) c[i % k]++;
	int cur = 0;
	for(int i = 0; i < n; i++){
		if(i & 1){
			for(int j = 0; j < m; j++){
				if(b[i][j] == 'R'){
					if(c[cur] == 0) cur++;
					c[cur]--;
				}
				b[i][j] = s[cur];
			}
		}
		else{
			for(int j = m-1; j >= 0; j--){
				if(b[i][j] == 'R'){
					if(c[cur] == 0) cur++;
					c[cur]--;
				}
				b[i][j] = s[cur];
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) cout << b[i][j];
		cout << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	while(n--) solve();
}