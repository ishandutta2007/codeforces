#include<bits/stdc++.h>
using namespace std;
const int N=150010;
typedef long double db;
typedef long long ll;
const db eps=1e-8;
 
int gi() {
	int x=0,o=1;char ch=getchar();
	while(!isdigit(ch)&&ch!='-') ch=getchar();
	if(ch=='-') o=-1,ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x*o;
}
 
int n;db c;
ll sum=0;
 
struct dat {
	int p,t;ll mn,mx;
	bool operator<(const dat &A) const {
		return 1ll*p*A.t>1ll*t*A.p;
	}
	db cal(ll t) {
		return (1.0-1.0*c*t/sum)*p;
	}
} a[N];
 
bool cmp(const dat &A,const dat &B) {
	return A.p<B.p;
}
 
int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	cin>>n;
	for(int i=1;i<=n;i++) a[i].p=gi();
	for(int i=1;i<=n;i++) a[i].t=gi();
	sort(a+1,a+n+1);
	for(int i=1,j=1;i<=n;i=j) {
		ll tmp=0;
		while(j<=n&&1ll*a[i].p*a[j].t==1ll*a[j].p*a[i].t) tmp+=a[j].t,++j;
		for(int k=i;k<j;k++) a[k].mn=sum+a[k].t,a[k].mx=sum+tmp;
		sum+=tmp;
	}
	sort(a+1,a+n+1,cmp);
	db l=0,r=1;
	for(int T=1;T<=100;T++) {
		c=(l+r)/2;
		db mx=-1e300;bool fl=1;
		for(int i=1,j=1;i<=n;i++) {
			while(j<=n&&a[j].p<a[i].p) mx=max(mx,a[j].cal(a[j].mn)),++j;
			if(a[i].cal(a[i].mx)+eps<mx) { fl=0;break; }
		}
		if(fl) l=c; else r=c;
	}
	printf("%.10Lf\n",l);
	return 0;
}