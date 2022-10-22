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
const long long mod=998244353;
long long getax(long long a,long long x){
	long long t1=1,t2=a,t3=1;
	while (x!=0){
		if (x%(t1*2)/t1==1){
			x=x-t1; t3=t3*t2%mod;
		}
		t1=t1*2; t2=t2*t2%mod;
	}
	return t3;
}
int i,j,k;
int n,m,q;
const int maxn=200010;
int ha[maxn],ans;
int x,y,z;
int main(){
	
	n=read(); m=read();
	for (i=1;i<=m;i++){
		x=read(); y=read();
		if (x>y) swap(x,y);
		ha[x]++; 
	}
	for (i=1;i<=n;i++){
		if (ha[i]==0) ans++;
	}
	q=read();
	for (i=1;i<=q;i++){
		x=read();
		if (x==1){
			y=read(); z=read();
			if (y>z) swap(y,z);
			ha[y]++; if (ha[y]==1) ans--;
		}
		if (x==2){
			y=read(); z=read();
			if (y>z) swap(y,z);
			ha[y]--; if (ha[y]==0) ans++;
		}
		if (x==3) 	printf("%d\n",ans); 
	}
	
	return 0;
}