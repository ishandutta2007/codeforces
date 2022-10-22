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
const int N=3e5+50;
int n;
LL cnt[2],ans=0;
int a[N],b[N],q[N];
LL x;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%I64d",&x);
		while(x){
			a[i]+=(x&1);
			x>>=1;
		}
	}
	cnt[0]=1;
	for(int i=1;i<=n;++i){
		b[i]=b[i-1]+a[i];
		ans+=cnt[(b[i]&1)];
		++cnt[(b[i]&1)];
	}
	int l,r,now;
	for(int k=2;k<=132;k+=2){
		now=0;l=1;r=0;
		for(int i=1,j=1;i<=n;++i){
			now+=a[i];
			while(l<=r&&a[q[r]]<a[i]) --r;
			q[++r]=i;
			while(now>k){
				now-=a[j];
				++j;
			}
			while(l<=r&&q[l]<j) ++l;
			if(now==k){
				if(a[q[l]]+a[q[l]]>now) --ans;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*

*/