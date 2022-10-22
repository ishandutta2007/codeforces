#include <bits/stdc++.h>
#define ll long long
using namespace std;
char st[100];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
	int T;
	T=read();
	while(T--){
		int n,num1=0,num2=0;
		scanf("%s",st+1);n=strlen(st+1);
		for(int i=1;i<=n;i+=2)num1=num1*10+(st[i]^48);
		for(int i=2;i<=n;i+=2)num2=num2*10+(st[i]^48);
		printf("%lld\n",1ll*(num1+1)*(num2+1)-2);
	}
	return 0;
}