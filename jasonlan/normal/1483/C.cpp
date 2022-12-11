#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
const int maxn=601100;
int n,m;
int h[maxn],b[maxn];
long long f[maxn],sg[maxn];
multiset <long long> se;
int s[maxn],st;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void process(){
	n=read();
	for(int i=1;i<=n;++i)
		h[i]=read();
	for(int i=1;i<=n;++i)
		b[i]=read();
	s[st=1]=1;
	se.insert(sg[st]+b[s[st]]);
	for(int i=1,p;i<n;++i){
		f[i]=*(--se.end());
		long long psg=f[i];
		while(st&&h[i+1]<h[s[st]]){
			se.erase(se.lower_bound(sg[st]+b[s[st]]));
			if(sg[st]>psg)psg=sg[st];
			--st;
		}
		s[++st]=i+1;
		sg[st]=psg;
		se.insert(psg+b[s[st]]);
	}
	printf("%lld\n",*(--se.end()));
}
int main(){
	int T=1;
	while(T--)process();
	return 0;
}