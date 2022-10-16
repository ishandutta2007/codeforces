#include<bits/stdc++.h>
#define MAX   100100
typedef long long ll;
const ll base=31LL;
const char fwd[]="forward";
const char bwd[]="backward";
const char all[]="both";
const char non[]="fantasy";
char s[MAX];
char u[111];
char v[111];
ll pw[MAX];
ll fh[MAX];
ll bh[MAX];
ll uh,vh;
int ls,lu,lv;
bool fe[MAX];
bool be[MAX];
void init(void) {
	scanf("%s",s);
	scanf("%s",u);
	scanf("%s",v);
	ls=strlen(s);
	lu=strlen(u);
	lv=strlen(v);
	int i;
	pw[0]=1LL;
	for (i=1;i<=MAX-7;i=i+1) pw[i]=pw[i-1]*base;
	fh[0]=0LL;
	bh[ls+1]=0LL;
	for (i=1;i<=ls;i=i+1) fh[i]=fh[i-1]+(s[i-1]-'a')*pw[i-1];
	for (i=ls;i>=1;i=i-1) bh[i]=bh[i+1]+(s[i-1]-'a')*pw[ls-i];
	uh=0LL;
	vh=0LL;
	for (i=0;i<lu;i=i+1) uh=uh+(u[i]-'a')*pw[i];
	for (i=0;i<lv;i=i+1) vh=vh+(v[i]-'a')*pw[i];
}
bool equal_f(const ll &hc,const int &i,const int &len) {
	if (i+len-1>ls) return (false);
	ll x=fh[i+len-1]-fh[i-1];
	ll y=hc*pw[i-1];
	return (x==y);
}
bool equal_b(const ll &hc,const int &i,const int &len) {
	if (i<len) return (false);
	ll x=bh[i-len+1]-bh[i+1];
	ll y=hc*pw[ls-i];
	return (x==y);
}
void process(void) {
	int i;
	fe[ls+1]=false;
	for (i=ls;i>=1;i=i-1)
		fe[i]=fe[i+1]|equal_f(vh,i,lv);
	be[0]=false;
	for (i=1;i<=ls;i=i+1)
		be[i]=be[i-1]|equal_b(vh,i,lv);
	bool fw=false;
	for (i=1;i+lu<=ls;i=i+1)
		if (equal_f(uh,i,lu) && fe[i+lu]) {
			fw=true;
			break;
		}
	bool bw=false;
	for (i=ls;i-lu>=1;i=i-1)
		if (equal_b(uh,i,lu) && be[i-lu]) {
			bw=true;
			break;
		}
	if (bw && fw) {
		printf("%s",all);
		return;
	}
	if (bw) {
		printf("%s",bwd);
		return;
	}
	if (fw) {
		printf("%s",fwd);
		return;
	}
	printf("%s",non);	
}
int main(void) {
	init();
	process();
	return 0;
}