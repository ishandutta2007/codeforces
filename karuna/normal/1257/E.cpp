#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
int a, b, c, x, N;
int A[200020];
int pfx[4][200020];
 
int main() {
	cin.tie(0); ios_base::sync_with_stdio(0);
 
	cin >> a >> b >> c; N=a+b+c;
	for (int i=0; i<a; i++) cin >> x, A[x] = 1;
	for (int i=0; i<b; i++) cin >> x, A[x] = 2;
	for (int i=0; i<c; i++) cin >> x, A[x] = 3;
 
	for (int i=1; i<=N; i++) {
		for (int j=1; j<=3; j++) pfx[j][i] = pfx[j][i-1]+1;
		pfx[A[i]][i]--;
	}
 
	int ans = N+1, mn = 0, cnt=0;
	for (int i=1; i<=N; i++) {
		if (A[i] != 2) ++cnt;
		mn = min(mn, pfx[1][i]-cnt);
		ans = min(ans, pfx[3][N]-pfx[3][i-1] + mn+cnt);
	}
 
	cout << ans-1;
}