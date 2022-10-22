// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=600010;
int i,j,k;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
long long n,a[maxn],thi,ans1,ans2,ans[50][2];
long long b[maxn],c[maxn],d[maxn];
void solve(long long l,long long r,long long thi,long long dep){
	if (l>=r) return;
	long long i,t1=0,t2=0;
	for (i=l;i<=r;i++) if (a[b[i]]&thi) c[i]=1; else c[i]=0;
	t1=0; t2=0;
	for (i=l;i<=r;i++){
		if (c[i]==0) t2=t2+t1;
		t1=t1+c[i];
	}
	ans[dep][0]=ans[dep][0]+t2;
	t1=0; t2=0;
	for (i=l;i<=r;i++){
		if (c[i]==1) t2=t2+t1;
		else t1++;
	}
	ans[dep][1]=ans[dep][1]+t2;
	t1=l;
	for (i=l;i<=r;i++) if (c[i]==0){ d[t1]=b[i]; t1++; }
	t2=t1-1;
	for (i=l;i<=r;i++) if (c[i]==1){ d[t1]=b[i]; t1++; }
	for (i=l;i<=r;i++) b[i]=d[i];
	if (thi==1) return;
	solve(l,t2,thi/2,dep-1);
	solve(t2+1,r,thi/2,dep-1);
}
int main(){
	
	n=read();
	for (i=1;i<=n;i++) a[i]=read();
	thi=1; for (i=1;i<=32;i++) thi=thi*2;
	for (i=1;i<=n;i++) b[i]=i;
	solve(1,n,thi,32);
	for (i=0,thi=1;i<=40;i++,thi=thi*2){
		ans1=ans1+min(ans[i][0],ans[i][1]);
		if (ans[i][0]>ans[i][1]) ans2=ans2+thi;
	}
	printf("%lld %lld\n",ans1,ans2);
	
	return 0;
}
/*

4
0 1 3 2

*/