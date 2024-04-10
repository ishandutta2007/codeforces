#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

const int MAXN = 100005;

int n, q, c, val, x1, y1, x2, y2, t;
int x[MAXN], y[MAXN];
int l[105] [105] [15];
int sum[105] [105] [15];

void ispis (int ind) {
	for (int i=0; i<5; i++) {
		for (int j=0; j<5; j++) {
			cout << sum[i] [j] [ind] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int add (int xx, int yy) {
	if (xx+yy>=c+1) return xx+yy-c-1; return xx+yy;
}

int main () {
	scanf("%d%d%d", &n, &q, &c);
	for (int i=0; i<n; i++) {
		scanf("%d%d%d", &x[i], &y[i], &val);
		for (int j=0; j<=c; j++) {
			l[x[i]] [y[i]] [j]+=add(val, j);
		}
	}
	for (int ii=0; ii<=c; ii++) {
		for (int i=1; i<102; i++) {
			for (int j=1; j<102; j++) {
				sum[i] [j] [ii]=l[i] [j] [ii]+sum[i] [j-1] [ii]+sum[i-1] [j] [ii]-sum[i-1] [j-1] [ii];
			}
		}
	}
	for (int i=0; i<q; i++) {
		scanf("%d%d%d%d%d", &t, &x1, &y1, &x2, &y2);
		int r=t%(c+1);
		int sol=sum[x2] [y2] [r]-sum[x2] [y1-1] [r]-sum[x1-1] [y2] [r]+sum[x1-1] [y1-1] [r];
		printf("%d\n", sol);
	}
	return 0;
}