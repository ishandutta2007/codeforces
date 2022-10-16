#include<cstdio>
#include<cstring>
#include<iostream>
#define MAX   4040
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
using namespace std;
typedef long long ll;
char s[MAX];
int t[MAX];
int c[MAX*9];
int a,n;
void init(void) {
	scanf("%d",&a);
	scanf("%s",s+1);
	n=strlen(s+1);
	FOR(i,1,n) t[i]=t[i-1]+s[i]-48;
	FOR(i,1,n) FOR(j,i,n) c[t[j]-t[i-1]]++;		
}
int count(const int &x) {
	if (x<0) return (0);
	if (x>n*9) return (0);
	return (c[x]);
}
void process(void) {
	ll res=0LL;
	if (a==0) {
		REP(i,n*9+1) res+=2LL*count(0)*count(i);
		res-=1LL*count(0)*count(0);
		cout<<res;
		return;
	}
	FOR(i,1,n*9) if (a%i==0) res+=1LL*count(i)*count(a/i);
	cout<<res;
}
int main(void) {
	init();
	process();
	return 0;
}