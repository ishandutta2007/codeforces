#include<bits/stdc++.h>
using namespace std;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if (c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int T,opt;
int n;
int i,j,k;
int ans;
const int maxn=1000010;
int ha[maxn],a[maxn];
void work(int x,int tot,int dep){
	if (x>n){ ha[tot]++; return; }
	work(x+1,tot+a[x],dep+1);
	work(x+1,tot,dep);
}
int main(){
	
	T=read();
	for (opt=1;opt<=T;opt++){
		n=read();
		for (i=1;i<=n;i++) a[i]=abs(read());
		sort(a+1,a+n+1);
		ans=0;
		memset(ha,0,sizeof(ha));
		work(1,0,0);
		for (i=0;i<maxn;i++) if (ha[i]>1) ans=1;		
		if (ans==1) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}