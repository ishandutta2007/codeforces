#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 55;

int n, m, sx, sy, ex, ey, len, sol;
char l[MAXN] [MAXN];
string s, p="ABCD";

bool ok (int x, int y) {
	return x>=0 && x<n && y>=0 && y<m && l[x] [y]!='#';
}

bool moze () {
	int x=sx, y=sy;
	for (int i=0; i<len; i++) {
		if (!ok(x, y)) return 0;
		if (l[x] [y]=='E') return 1;
		char c=p[s[i]-'0'];
		if (c=='A') x++;
		if (c=='B') y++;
		if (c=='C') x--;
		if (c=='D') y--;
		if (!ok(x, y)) return 0;
		if (l[x] [y]=='E') return 1;
	}
	if (l[x] [y]=='E') return 1; return 0;
}

int main () {
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> l[i] [j];
			if (l[i] [j]=='S') {
				sx=i; sy=j;
			} else if (l[i] [j]=='E') {
				ex=i; ey=j;
			}
		}
	}
	cin >> s;
	len=s.size();
	do {
		if (moze()) sol++;
	} while (next_permutation(p.begin(), p.end()));
	cout << sol;
	return 0;
}