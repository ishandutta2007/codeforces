#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=301000;
int n;
int a[maxn],f[maxn];
int s[maxn],st,q[maxn],qt;
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=res*10+ch-'0',ch=getchar();
	return res;
}
int main(){
	n=read();
	for(register int i=1;i<=n;++i){
		a[i]=read();f[i]=n;
	}
	f[1]=0;
	s[st=1]=1;q[qt=1]=1;
	for(register int i=2;i<=n;++i){
		bool res=1;
		while(st&&a[s[st]]<=a[i]){
			f[i]=min(f[i],f[s[st]]+1);
			res=a[s[st]]!=a[i];
			--st;
		}
		if(res&&st)
			f[i]=min(f[i],f[s[st]]+1);
		s[++st]=i;
		res=1;
		while(qt&&a[q[qt]]>=a[i]){
			f[i]=min(f[i],f[q[qt]]+1);
			res=a[q[qt]]!=a[i];
			--qt;
		}
		if(res&&qt)
			f[i]=min(f[i],f[q[qt]]+1);
		q[++qt]=i;
		f[i]=min(f[i],f[i-1]+1);
	}
	printf("%d",f[n]);
    return 0;
}