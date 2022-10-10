#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int i,j,k,n,m;
int main(){
	int T;
	cin>>T;
	while(T--){
		int a,b,c;
		a=read();b=read();c=read();
		if(a<c)printf("1 ");
		else printf("-1 ");
		if(1ll*a*b>c)printf("%d\n",b);
		else puts("-1");
	}
	return 0;
}