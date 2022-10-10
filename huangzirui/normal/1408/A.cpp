#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=100010;
int i,j,k,n,m,T,a[maxn],b[maxn],c[maxn],s[maxn];
int main(){
	cin>>T;
	while(T--){
		n=read();
		for(i=1;i<=n;i++)a[i]=read();
		for(i=1;i<=n;i++)b[i]=read();
		for(i=1;i<=n;i++)c[i]=read();
		for(i=1;i<n;i++){
			if(a[i]!=s[i-1])s[i]=a[i];
			else
			if(b[i]!=s[i-1])s[i]=b[i];
			else
			if(c[i]!=s[i-1])s[i]=c[i];
		}if(a[n]!=s[n-1] && a[n]!=s[1])s[n]=a[n];
		else if(b[n]!=s[n-1] && b[n]!=s[1])s[n]=b[n];
		else if(c[n]!=s[n-1] && c[n]!=s[1])s[n]=c[n];
		for(i=1;i<=n;i++)printf("%d ",s[i]);
		puts("");
	}
	return 0;
}