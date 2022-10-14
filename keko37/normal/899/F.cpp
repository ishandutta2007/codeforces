#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

const int MAXN = 200005;
const int LIM = 1005;

int n, m, d, cnt;
string s;
int cp[LIM], siz[LIM], nxt[MAXN], prv[MAXN];
int p[LIM] [LIM];

void brisi (int x) {
	nxt[prv[x]]=nxt[x];
	prv[nxt[x]]=prv[x];
}

void ispis () {
	for (int x=1; x<=cnt; x++) {
		if (siz[x]==0) continue;
		for (int i=cp[x], br=1; br<=siz[x]; i=nxt[i], br++) {
			cout << s[i];
		}
	}
}

void rem (int x, int l, int r, char c) {
	int org=siz[x];
	for (int curr=cp[x], br=1; br<=org; curr=nxt[curr], br++) {
		if (l<=br && br<=r && s[curr]==c) {
			brisi(curr);
			siz[x]--;
			p[x] [c]--;
			if (curr==cp[x]) cp[x]=nxt[cp[x]];
		}
	}
}

void upit (int l, int r, char c) {
	int len;
	for (int i=1, x=1; i<=n; i+=len, x++) {
		len=siz[x];
		if (p[x] [c]==0 || siz[x]==0) continue;
		int k=i+siz[x]-1;
		if (l<=i && i<=r && l<=k && k<=r) {
			rem(x, 1, siz[x], c);
		} else if (l<=i && i<=r) {
			rem(x, 1, r-i+1, c);
		} else if (l<=k && k<=r) {
			rem(x, l-i+1, siz[x], c);
		} else if (i<l && r<k) {
			rem(x, l-i+1, r-i+1, c);
		}
	}
}

int main () {
	cin >> n >> m >> s;
	s='.'+s+'.';
	d=sqrt(n);
	for (int i=1; i<=n; i++) {
		p[(i-1)/d+1] [s[i]]++;
		prv[i]=i-1;
		nxt[i]=i+1;
	}
	for (int i=1; i<=n; i+=d) {
		cnt++;
		cp[cnt]=i;
		siz[cnt]=d;
	}
	cp[cnt+1]=n+1;
	nxt[n+1]=n+1;
	siz[cnt]=cp[cnt+1]-cp[cnt];
	for (int i=0; i<m; i++) {
		int l, r; char c;
		scanf("%d %d", &l, &r);
		cin >> c;
		upit(l, r, c);
	}
	ispis();
	return 0;
}