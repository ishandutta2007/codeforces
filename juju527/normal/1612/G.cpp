#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5,mod=1e9+7,iv2=5e8+4;
int t[maxn];
int fc[maxn];
int num[2*maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
inline int add(int x){return x>=mod?x-mod:x;}
inline int sub(int x){return x<0?x+mod:x;}
int main(){
//    freopen("CF1612G.in","r",stdin);
//    freopen("CF1612G.out","w",stdout);
    int m,W=1e6;
	ll n=0;
	m=read();fc[0]=1;
	for(int i=1;i<=m;i++){
		int c;
		c=read();n+=c;
		t[c]++;fc[i]=1ll*fc[i-1]*i%mod;
	}
	for(int i=1;i<=W;i++){
		num[i-1+W]+=t[i];
		if(-1-i+W>=0)num[-1-i+W]-=t[i];
	}
	int res1=0,res2=1;
	ll sum=0;
	for(int i=2*W;i>=1;i--){
		if(num[i]==0)continue;
		if(i>1)num[i-2]+=num[i];
		ll l=n-sum-num[i]+1,r=n-sum;
		res1=add(res1+(l+r)%mod*((r-l+1)%mod)%mod*iv2%mod*sub(i-W)%mod);
		res2=1ll*res2*fc[num[i]]%mod;
		sum+=num[i];
	}
	printf("%d %d\n",res1,res2);
    return 0;
}