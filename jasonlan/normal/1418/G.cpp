#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define mp make_pair
using namespace std;
const int maxn=501000,mod1=998244353,mod2=1e9+7,base=20201119;
int n;
int a[maxn],cnt[maxn],cnta[maxn];
int hash1[maxn],pow1[maxn],hash2[maxn],pow2[maxn];
map <pair<int,int>,int> m;
long long ans;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int qmod(int x,int md){
	return x>=md?x-md:x;
}
void reset(){
	pow1[0]=pow2[0]=1;
	for(register int i=1;i<=n;++i){
		pow1[i]=1ll*pow1[i-1]*base%mod1;
		pow2[i]=1ll*pow2[i-1]*base%mod2;
	}
}
int main(){
	n=read();
	for(register int i=1;i<=n;++i)
		a[i]=read();
	reset();
	m[mp(0,0)]=1;
	for(register int i=1,lp=0;i<=n;++i){
		++cnt[a[i]];++cnta[a[i]];
		while(cnt[a[i]]>3){
			--m[mp(hash1[lp],hash2[lp])];
			--cnt[a[++lp]];
		}
		if(cnta[a[i]]%3){
			hash1[i]=qmod(hash1[i-1]+pow1[a[i]],mod1);
			hash2[i]=qmod(hash2[i-1]+pow2[a[i]],mod2);
		}
		else{
			hash1[i]=qmod(hash1[i-1]-qmod(pow1[a[i]]<<1,mod1)+mod1,mod1);
			hash2[i]=qmod(hash2[i-1]-qmod(pow2[a[i]]<<1,mod2)+mod2,mod2);
		}
		ans+=m[mp(hash1[i],hash2[i])];
		++m[mp(hash1[i],hash2[i])];
	}
	printf("%lld",ans);
	return 0;
}