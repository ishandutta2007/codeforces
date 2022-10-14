#include<iostream>
#include<cstdio>

using namespace std;

const int MAXN = 1000005;

int n, m, k, sol, cnt;
int l[MAXN];

int main () {
	cin >> n >> m >> k;
	for (int i=0; i<n; i++) {
		int x;
		scanf("%d", &x);
		l[x]=1;
		if (1<=x && x<=m) cnt++;
	}
	for (int i=m; cnt>=k; i--) {
		if (l[i]==1) {
			l[i]=0;
			cnt--;
			sol++;
		}
	}
	int x=1, y=m;
	while (y<MAXN-2) {
		if (cnt==k) {
			l[y]=0;
			cnt--;
			sol++;
		}
		cnt-=l[x]; x++;
		y++; cnt+=l[y];
	}
	cout << sol;
	return 0;
}