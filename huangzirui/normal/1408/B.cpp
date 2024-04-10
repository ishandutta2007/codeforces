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
int i,j,k,n,m,T,a[maxn],s;
int main(){
	T=read();
	a[0]=-1;
	while(T--){
		s=0;
		n=read();m=read();
		for(i=1;i<=n;i++)a[i]=read();
		if(m==1){
			bool b=0;
			for(i=2;i<=n;i++)if(a[i]!=a[i-1])b=1;
			if(b)puts("-1");
			else puts("1");
		}else{
			for(i=1;i<=n;i++)
				if(a[i]!=a[i-1])s++;
			if(s!=1)s--;
			int ans=s/(m-1)+1;
			if(s%(m-1)==0)ans--;
			printf("%d\n",ans);
		}
	}
	return 0;
}