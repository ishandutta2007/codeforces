#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll read(){
    ll x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
ll f(ll x){
	ll y=x%4;
	if(y==0)return x;
	if(y==1)return 1;
	if(y==2)return x+1;
	if(y==3)return 0;
}
int main(){
//    freopen("CF15C.in","r",stdin);
//    freopen("CF15C.out","w",stdout);
   	int n;
	n=read();
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll x,m;
		x=read();m=read();
		ans^=f(x+m-1)^f(x-1);
	}
	if(ans>0)printf("tolik");
	else printf("bolik");
    return 0;
}