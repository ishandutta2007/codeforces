#include<bits/stdc++.h>
using namespace std;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if (c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
const int maxn=200010;
int T=1,opt;
int n,m;
int t1,t2,t3;
int a[maxn];
int check(int mid){
	int t1=m;
	for (int i=mid;i<=n;i++){
		if (t1<=0) return -1;
		if (a[i]>t1) t1--;
	}
	return t1;
}
void getcheck(int ans){
	int t1=m;
	for (int i=1;i<ans;i++){
		if (t1<=0){
			printf("0"); continue;
		}
		if (a[i]<=t1) printf("1"); else printf("0");
	}
	for (int i=ans;i<=n;i++){
		if (t1<=0){
			printf("0"); continue;
		}
		printf("1");
		if (a[i]>t1) t1--;
	}
	printf("\n");
}
int l,r,mid,ans;
int main(){
	T=read();
	for (opt=1;opt<=T;opt++){
		n=read(); m=read();
		for (int i=1;i<=n;i++) a[i]=read();
		l=1; r=n+1; ans=n+1;
		while (l<=r){
			mid=(l+r)/2;
			if (check(mid)>=0){
				ans=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		getcheck(ans);
	}

	return 0;
}