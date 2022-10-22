#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
ull pw[19];
ll read(){
    ll x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int main(){
//    freopen("CF468C.in","r",stdin);
//    freopen("CF468C.out","w",stdout);
    ll a;
	a=read();
	ll l=1,r=1e18,s=0;
	pw[0]=1;
	for(int i=1;i<=18;i++)pw[i]=pw[i-1]*10%a;
	for(int c=1;c<10;c++){
		s+=pw[17]*c%a*18%a;
//		cout<<(ll)(one*c*pw[17]%a*18%a)<<endl;
		if(s>=a)s-=a;
	}
	s++;
	if(s>=a)s-=a;
//	cout<<s<<endl;
	if(s==0){
		printf("%lld %lld\n",l,r);
		return 0;
	}
	printf("%lld %lld\n",l+a-s,r+a-s);
    return 0;
}