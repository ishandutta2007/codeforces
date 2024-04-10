#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char s[110000]; int n;
char t[110000]; int m;
int nxt[110000],z[110000],p[110000],a[110000];
void getnxt(char *s,int n){
	nxt[1]=0; int k=0;
	for (int i=2;i<=n;i++){
		while (k&&s[k+1]!=s[i]) k=nxt[k];
		if (s[k+1]==s[i]) k++;
		nxt[i]=k;
	}
}
void getZ(char *s,int n){
	z[1]=n; int l=0,r=0;
	for (int i=2;i<=n;i++){
		int tmp=0;
		if (i<=r) tmp=min(z[i-l+1],r-i+1);
		while (i+tmp<=n&&1+tmp<=n&&s[i+tmp]==s[1+tmp]) tmp++;
		z[i]=tmp; if (i+tmp-1>r) l=i,r=i+tmp-1;
	}
}
void getP(char *s,int n,char *t,int m){
	getZ(t,m); int l=0,r=0;
	for (int i=1;i<=n;i++){
		int tmp=0;
		if (i<=r) tmp=min(z[i-l+1],r-i+1);
		while (i+tmp<=n&&1+tmp<=m&&s[i+tmp]==t[1+tmp]) tmp++;
		p[i]=tmp; if (i+tmp-1>r) l=i,r=i+tmp-1;
	}
}
int main(){
	scanf("%s",s+1); n=strlen(s+1);
	scanf("%s",t+1); m=strlen(t+1);
	getP(s,n,t,m); getnxt(t,m);
	for (int i=1;i<=m;i++){
		if (!nxt[i]) continue;
		int j=nxt[i];
		a[i-j]++;
	}
	for (int i=1;i<=m;i++) a[i]+=a[i-1];
	ll ans=1ll*n*m;
	for (int i=2;i<=n;i++) ans-=a[p[i]];
	printf("%lld\n",ans);
	return 0;
}