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
int i,j,k,n,m,T,a[maxn];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+1+n);
		if(n&1)printf("%d ",a[n/2+1]);
		for(i=n/2;i>=1;i--)printf("%d %d ",a[i],a[n-i+1]);
		puts("");
	}
	return 0;
}