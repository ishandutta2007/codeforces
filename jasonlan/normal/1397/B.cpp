#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
const int maxm=101000;
int n;
ll p[maxm],ans,INF;
inline ll read(){
	ll res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	n=read();
	for(register int i=0;i<n;++i){
		p[i]=read();INF+=p[i];
    }
	sort(p,p+n);
	ans=INF;
	for(register ll c=1,d,pans;c<=p[n-1];++c){
		d=1;pans=0;
		for(register int i=0;i<n;++i,d*=c){
			if(d-p[i]>=INF){
				printf("%lld\n",ans);
				return 0;
			}
			pans+=d>=p[i]?d-p[i]:p[i]-d;
		}
		ans=min(pans,ans);
	}
	printf("%lld\n",ans);
	return 0;
}