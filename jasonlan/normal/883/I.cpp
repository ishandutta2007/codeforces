#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=300010;
int n,k;
int a[maxn],f[maxn];
int s[maxn],st,se;
inline ll read(){
	ll res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=res*10+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	n=read();k=read();
	for(register int i=1;i<=n;++i)
		a[i]=read();
	sort(a+1,a+1+n);
	for(register int i=k;i<=n;++i){
		while(st<se&&max(f[s[st]],a[i]-a[s[st]+1])>=max(f[s[st+1]],a[i]-a[s[st+1]+1]))
			++st;
		if(i-k>=k){
			while(se>=st&&max(f[s[se]],a[i]-a[s[se]+1])>=max(f[i-k],a[i]-a[i-k+1]))
				--se;
			s[++se]=i-k;
		}
		f[i]=max(f[s[st]],a[i]-a[s[st]+1]);
	}
	printf("%d",f[n]);
    return 0;
}