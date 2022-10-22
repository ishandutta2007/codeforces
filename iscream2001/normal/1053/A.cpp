#pragma GCC optimize("-O3")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<vector>
#include<map>
#define pa pair<LL,LL>
#define LL long long
using namespace std;
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline void Out(int a){
    if(a>9) Out(a/10);
    putchar(a%10+'0');
}
const int inf=1e9;
const LL mod=1e9+7;
LL n,m,k,S;
LL gcd(LL a,LL b){
return b ? gcd(b,a%b) : a;
}

int main(){
	cin>>n>>m>>k;
	LL a,N=n,M=m;
	a=gcd(k,n);n/=a;k/=a;
	a=gcd(k,m);m/=a;k/=a;
	if(k==2){
		printf("YES\n");
		cout<<0<<" "<<0<<endl;
		cout<<0<<" "<<m<<endl;
		cout<<n<<" "<<0<<endl;
		return 0;
	}
	else if(k==1){
		if(n+n<=N){
			n=n+n;
			printf("YES\n");
			cout<<0<<" "<<0<<endl;
		cout<<0<<" "<<m<<endl;
		cout<<n<<" "<<0<<endl;
		return 0;
		}
		if(m+m<=M){
			m=m+m;
			printf("YES\n");
			cout<<0<<" "<<0<<endl;
		cout<<0<<" "<<m<<endl;
		cout<<n<<" "<<0<<endl;
		return 0;
		}
		printf("NO\n");return 0;
	}
	else{
		printf("NO\n");return 0;
	}
	
}
/*

*/