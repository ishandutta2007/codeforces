#include<iostream>
#include<cstring>

using namespace std;

const int MAXN = 1005;
const int INF = 1000000007;

int n;
int cost[10];
char l[5] [MAXN];
int dp[MAXN] [6] [6] [6] [6];

int f (int x, int a, int b, int c, int d) {
	if (x==n) return 0;
	if (dp[x] [a] [b] [c] [d]!=-1) return dp[x] [a] [b] [c] [d];
	int res=INF;
	int p[5];
	for (int len=1; len<=4; len++) {
		if (x+len>n) break;
		for (int r=0; r+len-1<4; r++) {
			p[0]=a; p[1]=b; p[2]=c; p[3]=d;
			for (int i=r; i<r+len; i++) {
				p[i]=max(p[i], len);
			}
			if (p[0]==a && p[1]==b && p[2]==c && p[3]==d) continue;
			res=min(res, cost[len]+f(x, p[0], p[1], p[2], p[3]));
		}
	}
	if ((a || l[0] [x]=='.') && (b || l[1] [x]=='.') && (c || l[2] [x]=='.') && (d || l[3] [x]=='.')) {
		res=min(res, f(x+1, max(a-1, 0), max(b-1, 0), max(c-1, 0), max(d-1, 0)));
	}
	dp[x] [a] [b] [c] [d]=res;
	return res;
}

int main () {
	memset(dp, -1, sizeof dp);
	cin >> n;
	for (int i=1; i<=4; i++) {
		cin >> cost[i];
	}
	for (int i=0; i<4; i++) {
		for (int j=0; j<n; j++) {
			cin >> l[i] [j];
		}
	}
	cout << f(0, 0, 0, 0, 0);
	return 0;
}