#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<cstring>
#include<map>
#define LL long long
using namespace std;

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void Out(int x){
	if(x>9) Out(x/10);
	putchar('0'+x%10);
}
int gcd(int x,int y){
	if(!y) return x;
	return gcd(y,x%y);
}
LL qpow(LL x,LL y,LL P){
	LL re=1;
	while(y){
		if(y&1) re=re*x%P;
		x=x*x%P;y>>=1;
	}
	return re;
}
const int N=2e5+10;
const LL P=1e9+7;
const LL inf=1e18;
LL n,b,p,t;
LL cal(){
	LL re=0,x=n;
	while(x>0){
		x=x/p;
		re+=x;
	}
	return re;
}
int main(){
	cin>>n>>b;
	LL y,ans=inf;
	for(LL i=2;i<=sqrt(b);++i)
		if(b%i==0){
			p=i;
			t=0;
			while(b%i==0){
				b/=i;
				++t;
			}
			y=cal();
			y=y/t;
			//cout<<y<<endl;
			ans=min(ans,y);
		}
	if(b>1){
		p=b;
		t=1;
		y=cal();
		//cout<<y<<endl;
		ans=min(ans,y);
	}
	cout<<ans<<endl;
	return 0;
} 
/*

*/