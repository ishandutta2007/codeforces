#include <bits/stdc++.h>
using namespace std;

int h, w, nf;
string g[500];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> h >> w;
	for(int i=0; i<h; ++i) {
		cin >> g[i];
		for(int j=0; j<w; ++j)
			nf+=g[i][j]=='*';
	}
	for(int i=0; i<h; ++i) {
		for(int j=0; j<w; ++j) {
			if(g[i][j]^'*')
				continue;
			int cf=1, a=0, b=0, c=0, d=0;
			for(int k=i-1; ~k&&g[k][j]=='*'; --k) {
				++cf;
				a=1;
			}
			for(int k=i+1; k<h&&g[k][j]=='*'; ++k) {
				++cf;
				b=1;
			}
			for(int k=j-1; ~k&&g[i][k]=='*'; --k) {
				++cf;
				c=1;
			}
			for(int k=j+1; k<w&&g[i][k]=='*'; ++k) {
				++cf;
				d=1;
			}
			if(cf==nf&&a*b*c*d) {
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
}