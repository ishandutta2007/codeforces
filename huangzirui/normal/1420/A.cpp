#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=50010;
int i,j,k,n,m,a[maxn];
int main(){
	int T=read();
	while(T--){
		n=read();
		for(i=1;i<=n;i++)a[i]=read();
		int b=0;
		for(i=1;i<n;i++)if(a[i]<=a[i+1])b=1;
		if(b)puts("YES");
		else puts("NO");
	}
	return 0;
}