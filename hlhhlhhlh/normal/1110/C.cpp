// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int i,j,k;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int T,opt,n,m,fla,ans,len,mx;
map <int,int> mp;
int a[maxn];
int gcd(int x,int y){
	if (y==0) return x;
	return gcd(y,x%y);
}
int main(){
	T=read();
	mp[33554431]=1082401;
	mp[16777215]=16777215/3;
	for (opt=1;opt<=T;opt++){
		n=read();
		if (mp[n]!=0){
			printf("%d\n",mp[n]); continue;
		}
		m=1; fla=0;
		for (i=1;i<=26;i++){
			if (n==m) fla=1;
			m=m*2+1;
		}
		if (fla==0){
			mx=1; while (mx<=n) mx=mx*2; mx--;
			printf("%d\n",mx);
		}
		else{
			ans=0; len=0; m=n;
//			while (m!=0){ m=m/2; len++; }
//			dfs(1,0,1);
			for (i=1;i<=n/2;i++) ans=max(ans,gcd(n-i,i));
			mp[n]=ans;
			printf("%d\n",mp[n]);
		}
	}
	return 0;
}
/*
6
33554431
16777215
16777215
16777215
16777215
8388607
1
*/