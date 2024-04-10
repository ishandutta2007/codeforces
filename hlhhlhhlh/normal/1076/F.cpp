// user:halahen
#include<bits/stdc++.h>
using namespace std;
const long long maxn=300010;
long long i,j,k;
long long n,m;
long long a[maxn],b[maxn];
long long f[maxn];
long long x,y;
long long read(){
	long long tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
int main(){
	n=read(); m=read();
	for (i=1;i<=n;i++) a[i]=read();
	for (i=1;i<=n;i++) b[i]=read();
	if (m==1){
		x=0;
		for (i=1;i<=n;i++){
			if (a[i]>b[i]){
				if (a[i]-b[i]>1){
					printf("NO\n");
					return 0;
				}
				if (x<0){
					printf("NO\n");
					return 0;
				}
				x=-1;
			}
			if (a[i]<b[i]){
				if (b[i]-a[i]>1){
					printf("NO\n");
					return 0;
				}
				if (x>0){
					printf("NO\n");
					return 0;
				}
				x=1;
			}
		}
		printf("YES\n");
		return 0;
	}
	for (i=n-1;i>=1;i--){
		if (a[i+1]>b[i+1]){
			f[i]=1;
		}
		if (a[i+1]<b[i+1]){
			f[i]=0;
		}
		if (a[i+1]==b[i+1]){
			f[i]=f[i+1];
		}
	}
	x=0;
	for (i=1;i<=n;i++){
		if ((a[i]==b[i])&&(a[i]==1)){
			if (abs(x)==m){
				x=x/m;
			}
			else{
				x=0;
			}
			continue;
		}
		if (a[i]>b[i]){
			if (x>=0){
				y=(b[i]+1)*m-a[i];
				if ((b[i]+1)*m<a[i]){
					printf("NO\n");
					return 0;
				}
			}
			else{
				y=(b[i]+1)*m-a[i]+x;
				if ((b[i]+1)*m<a[i]-x){
					printf("NO\n");
					return 0;
				}
			}
			if (f[i]==0){
				x=0;
			}
			else{
				if (y>=m) x=0; else x=y-m;
			}
		}
		else{
			if (x<=0){
				y=(a[i]+1)*m-b[i];
				if ((a[i]+1)*m<b[i]){
					printf("NO\n");
					return 0;
				}
			}
			else{
				y=(a[i]+1)*m-b[i]-x;
				if ((a[i]+1)*m<b[i]+x){
					printf("NO\n");
					return 0;
				}
			}
			if (f[i]==1){
				x=0;
			}
			else{
				if (y>=m) x=0; else x=m-y;
			}
			
		}
	}
	printf("YES\n");
	return 0;
}