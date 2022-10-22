#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int power(int x,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*x%mod;
		x=1ll*x*x%mod;
		b>>=1;
	}
	return ans;
}
int main(){
//    freopen("CF1265E.in","r",stdin);
//    freopen("CF1265E.out","w",stdout);
    int n;
	n=read();
	int iv=power(100,mod-2);
	int sum=0,pai=1,p;
	for(int i=1;i<=n;i++){
		p=1ll*read()*iv%mod;
		sum+=pai;
		if(sum>=mod)sum-=mod;
		pai=1ll*pai*p%mod;
	}
	int f1=1ll*sum*power(pai,mod-2)%mod;
    printf("%d\n",f1);
	return 0;
}