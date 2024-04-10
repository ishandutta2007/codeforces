#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=105;
int a[maxn],b[maxn],c[maxn];
int p[maxn];
int read(){
	int x=0,y=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*y;
}
int main(){
	int t;
	t=read();
	while(t--){
		int n;
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)b[i]=read();
		for(int i=1;i<=n;i++)c[i]=read();
		for(int i=1;i<n;i++){
			if(p[i-1]^a[i])p[i]=a[i];
			else if(p[i-1]^b[i])p[i]=b[i];
		}
		if(p[n-1]!=a[n]&&p[1]!=a[n])p[n]=a[n];
		else if(p[n-1]!=b[n]&&p[1]!=b[n])p[n]=b[n];
		else p[n]=c[n];
		for(int i=1;i<=n;i++)printf("%d ",p[i]);
		printf("\n");
	}
	return 0;
}