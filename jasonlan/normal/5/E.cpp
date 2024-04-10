#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
typedef long long ll;
const int maxn=1010000;
ll ans;
int n,mx,h[maxn],q[maxn];
int s[maxn],st,cnt[maxn];
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=res*10+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main()
{
	n=read();mx=1;
	for(register int i=1;i<=n;++i){
		h[i]=read();
		if(h[i]>h[mx])mx=i;
	}
	ans=n-1;
	for(register int i=mx+1;i<=n;++i)
		q[i-mx+1]=h[i];
	for(register int i=1;i<mx;++i)
		q[i+n-mx+1]=h[i];
	for(register int i=2;i<=n;++i){
		while(s[st]<q[i]&&st)ans+=cnt[st--];
		if(s[st]!=q[i]){
			s[++st]=q[i];cnt[st]=0;
		}
		ans+=cnt[st]++;
	}
	while(st>1)ans+=cnt[st--];
	cout<<ans;
	return 0;
}