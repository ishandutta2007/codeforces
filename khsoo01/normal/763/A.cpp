#include<bits/stdc++.h>
using namespace std;
int n, a[100005];
bool kirei[100005];

vector<int> adj[100005];

void prec (int cur, int prv) {
	kirei[cur] = true;
	for(auto &nxt : adj[cur]) {
		if(nxt == prv) continue;
		prec(nxt, cur);
		if(!kirei[nxt] || a[nxt] != a[cur]) {
			kirei[cur] = false;
		}
	}
}

void solve (int cur, int prv) {
	int col = a[cur], fuck = 0, cnt = 0;
	bool diff = (prv && a[cur] != a[prv]);
	for(auto &nxt : adj[cur]) {
		if(nxt == prv) continue;
		if(kirei[nxt] && col != a[nxt]) diff = true;
		if(!kirei[nxt]) {cnt++; fuck = nxt;}
	}
	if(!cnt) {printf("YES\n%d\n",cur); exit(0);}
	else if(cnt == 1 && !diff) solve(fuck, cur);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++) {
		int A, B;
		scanf("%d%d",&A,&B);
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	prec(1, 0);
	solve(1, 0);
	puts("NO");
}