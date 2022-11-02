#include<bits/stdc++.h>
using namespace std;
const int N = 2005, inf = 1e9;
 
int n, p[N], l[N], r[N], cur, ans;
int dep[N], chi[N], tot, rt;
bool blk[N];
 
vector<int> adj[N];
 
void calc (int C, int P) {
	chi[C] = 1;
	for(auto &T : adj[C]) {
		if(T == P || blk[T]) continue;
		calc(T, C);
		chi[C] += chi[T];
	}
}
 
int findcen (int C, int P) {
	int mx = 0;
	for(auto &T : adj[C]) {
		if(T == P || blk[T]) continue;
		if(chi[mx] < chi[T]) mx = T;
	}
	if(chi[mx] <= tot/2) return C;
	return findcen(mx, C);
}
 
int leaf (int C) {return (l[C] ? leaf(l[C]) : C);}
 
int Test (int C) {
	if(!l[C] || !r[C]) return 0;
	int L = leaf(l[C]), R = leaf(r[C]);
	printf("%d %d %d\n",(L+1)/2,(R+1)/2,cur);
	fflush(stdout);
	char res[2];
	scanf("%s",res);
	return (res[0] - 'X');
}
 
int solve (int I) {
	int cen, res;
	calc(I, 0); tot = chi[I];
	if(tot == 1) return I;
	cen = findcen(I, 0);
	res = Test(cen);
	if(res == 0) {
		blk[l[cen]] = blk[r[cen]] = true;
		return solve(cen);
	}
	else {
		blk[cen] = true;
		return solve(res - 1 ? l[cen] : r[cen]);
	}
}
 
void cdep (int I) {
	if(!l[I] || !r[I]) return;
	dep[l[I]] = dep[I] + 1;
	cdep(l[I]);
	dep[r[I]] = dep[I] + 1;
	cdep(r[I]);
}
 
int main()
{
	scanf("%d",&n);
	p[1] = 2; p[3] = 2;
	l[2] = 1; r[2] = 3;
	blk[0] = true;
	for(int i=3;i<=n;i++) {
		cur = i;
		for(int j=1;j<=2*i-3;j++) {
			adj[j].clear(); blk[j] = false;
			if(!p[j]) rt = j;
			if(p[j]) adj[j].push_back(p[j]);
			if(l[j]) adj[j].push_back(l[j]);
			if(r[j]) adj[j].push_back(r[j]);
		}
		dep[rt] = 0; dep[0] = inf;
		cdep(rt); ans = solve(1);
		if(l[p[ans]] != ans) swap(l[p[ans]], r[p[ans]]);
		l[p[ans]] = 2*i-2; p[2*i-2] = p[ans];
		l[2*i-2] = ans; p[ans] = 2*i-2;
		r[2*i-2] = 2*i-1; p[2*i-1] = 2*i-2;
	}
	puts("-1");
	fflush(stdout);
	for(int i=1;i<=2*n-1;i++) {
		printf("%d ",(p[i] ? p[i] : -1));
	}
	puts("");
	fflush(stdout);
 
	return 0;
}