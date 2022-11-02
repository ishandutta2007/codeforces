#include<bits/stdc++.h>
using namespace std;
const int N = 300005;

int n, m, d[N], prv[N];
bool vis[N], chk[N], rab[N];

vector<int> adj[N], alt[N];

queue<int> q;

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) {
		int A, B;
		scanf("%d%d",&A,&B);
		adj[A].push_back(B);
		adj[B].push_back(A);
		if(A != 1 && B != 1) {
			alt[A].push_back(B);
			alt[B].push_back(A);
		}
	}
	vis[1] = true; q.push(1);
	while(!q.empty()) {
		int C = q.front(); q.pop();
		for(auto &T : adj[C]) {
			if(!vis[T]) {
				vis[T] = true;
				d[T] = d[C] + 1;
				prv[T] = C;
				q.push(T);
			}
		}
	}
	vector<int> ans;
	if(vis[n] && d[n] <= 3) {
		for(int i=n;i;i=prv[i]) {
			ans.push_back(i);
		}
		printf("%d\n",d[n]);
		for(int i=ans.size();i--;) {
			printf("%d ",ans[i]);
		}
		puts(""); return 0;
	}
	int I = -1;
	for(int i=1;i<=n;i++) {
		if(vis[i] && d[i] == 2) {I=i; break;}
	}
	if(I != -1) {
		puts("4");
		for(int i=I;i;i=prv[i]) {
			ans.push_back(i);
		}
		for(int i=ans.size();i--;) {
			printf("%d ",ans[i]);
		}
		printf("1 %d\n", n);
		return 0;
	}
	for(auto &T : adj[1]) rab[T] = true;
	fill(vis+1, vis+1+n, false);
	for(int i=2;i<=n;i++) {
		if(!rab[i] || vis[i]) continue;
		q.push(i); vis[i] = true; d[i] = 0; prv[i] = 0;
		int Z = -1;
		while(!q.empty()) {
			int C = q.front(); q.pop();
			if(d[C] == 2) {Z = C; break;}
			for(auto &T : alt[C]) {
				if(!vis[T]) {
					vis[T] = true;
					d[T] = d[C] + 1;
					prv[T] = C;
					q.push(T);
				}
			}
		}
		if(Z != -1) {
			printf("5\n1 ");
			for(int j=Z;j;j=prv[j]) {
				ans.push_back(j);
			}
			for(int j=ans.size();j--;) {
				printf("%d ",ans[j]);
			}
			printf("%d %d\n",i,n);
			return 0;
		}
		for(auto &T : alt[i]) chk[T] = true;
		for(auto &T : alt[i]) {
			if(alt[T].size() != alt[i].size()) {
				for(auto &C : alt[T]) chk[C] = false;
				chk[T] = false;
				for(auto &C : alt[i]) if(chk[C]) {Z = C; break;}
				printf("5\n1 %d %d %d %d %d\n",T,i,Z,T,n);
				return 0;
			}
		}
	}
	puts("-1");
}