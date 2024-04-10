#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
int n;
int cnt[(1<<24)+7];
int res[(1<<24)+7];
int sqr(int x) {
	return (x*x);
}
int getmask(string &s) {
	int ret=0;
	FORE(it,s) ret=ret|(1<<(*it-'a'));
	return (ret);
}
void init(void) {	
	cin >> n;
	REP(i,n) {
		string s;
		cin >> s;
		cnt[getmask(s)]++;
	}
}
void count(int l,int r) {
	if (r-l==1) {
		res[l]=cnt[l];
		return;
	}
	int m=(l+r)>>1;
	count(l,m);
	count(m,r);
	REP(i,r-m) res[m+i]+=res[l+i];
}
void process(void) {
	int ans=0;
	count(0,1<<24);
	REP(i,1<<24) ans=ans^sqr(n-res[i]);
	printf("%d",ans);
}
int main(void) {
	ios::sync_with_stdio(false);
	init();
	process();
	return 0;
}