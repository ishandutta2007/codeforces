#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=110;
int i,j,k,n,m;
int a[maxn],b[maxn];
int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++)a[i]=read();
		for(i=1;i<=n;i++)b[i]=read();
		sort(a+1,a+1+n);
		sort(b+1,b+1+n);
		for(i=1;i<=n;i++)printf("%d ",a[i]);printf("\n");
		for(i=1;i<=n;i++)printf("%d ",b[i]);printf("\n");
	}return 0;
}