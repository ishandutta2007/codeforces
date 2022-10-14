#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>

using namespace std;

const int MAXN = 201005;
const int LIM = 505;

int n, d, cnt, q;
int r[MAXN], p[LIM], prv[MAXN], nxt[MAXN];
int poc[LIM] [101], kraj[LIM] [101];

inline void spoji (int ind, int x, int y) {
	if (kraj[ind] [x]==0) return;
	if (kraj[ind] [y]==0) {
		poc[ind] [y]=poc[ind] [x];
		kraj[ind] [y]=kraj[ind] [x];
	} else {
		nxt[kraj[ind] [y]]=poc[ind] [x];
		prv[poc[ind] [x]]=kraj[ind] [y];
		kraj[ind] [y]=kraj[ind] [x];
	}
	poc[ind] [x]=kraj[ind] [x]=0;
}

inline void brisi (int t) {
	nxt[prv[t]]=nxt[t];
	prv[nxt[t]]=prv[t];
}

inline void cijeli (int ind, int x, int y, int l, int r) {
	int gotov;
	for (int i=poc[ind] [x]; ; i=nxt[i]) {
		gotov=0;
		if (l<=i && i<=r) {
			if (poc[ind] [x]==kraj[ind] [x]) {
				poc[ind] [x]=kraj[ind] [x]=0;
				gotov=1;
			} else if (i==poc[ind] [x]) {
				poc[ind] [x]=nxt[poc[ind] [x]];
			} else if (i==kraj[ind] [x]) {
				kraj[ind] [x]=prv[kraj[ind] [x]];
				gotov=1;
			} else {
				brisi(i);
			}
			if (kraj[ind] [y]==0) {
				poc[ind] [y]=kraj[ind] [y]=i;
			} else {
				nxt[kraj[ind] [y]]=i;
				prv[i]=kraj[ind] [y];
				kraj[ind] [y]=i;
			}
		}
		if (i==kraj[ind] [x] || i==0 || kraj[ind] [x]==0 || gotov) break;
	}
}

void upit (int lef, int rig, int x, int y) {
	if (x==y) return;
	int lo=1, hi=d, from, to=-1;
	for (int i=1; i<=cnt; i++, lo+=d, hi+=d, to=-1) {
		if (lef<=lo && hi<=rig) {
			spoji(i, x, y);
		} else if (lef<=hi && hi<=rig) {
			from=lef; to=hi;
		} else if (lef<=lo && lo<=rig) {
			from=lo; to=rig;
		} else if (lo<=lef && rig<=hi) {
			from=lef; to=rig;
		}
		if (to==-1) continue;
		cijeli(i, x, y, from, to);
	}
}

void ispis (int ind, int val) {
	if (poc[ind] [val]==0 || kraj[ind] [val]==0) return;
	for (int i=poc[ind] [val]; ; i=nxt[i]) {
		r[i]=val;
		if (i==kraj[ind] [val] || i==0) break;
	}
}

int main () {
	cin >> n;
	int org=n;
	for (int i=1; i<=n; i++) {
		scanf("%d", &r[i]);
	}
	d=sqrt(n);
	while (n%d!=0) {
		n++; r[n]=1;
	}
	cnt=n/d;
	for (int i=1; i<=n; i++) {
		int ind=(i-1)/d+1;
		if (poc[ind] [r[i]]==0) {
			poc[ind] [r[i]]=kraj[ind] [r[i]]=i;
		} else {
			nxt[kraj[ind] [r[i]]]=i;
			prv[i]=kraj[ind] [r[i]];
			kraj[ind] [r[i]]=i;
		}
	}
	cin >> q;
	for (int i=0; i<q; i++) {
		int lef, rig, x, y;
		scanf("%d%d%d%d", &lef, &rig, &x, &y);
		upit(lef, rig, x, y);
	}
	for (int i=1; i<=cnt; i++) {
		for (int j=1; j<=100; j++) {
			ispis(i, j);
		}
	}
	for (int i=1; i<=org; i++) {
		printf("%d ", r[i]);
	}
	return 0;
}