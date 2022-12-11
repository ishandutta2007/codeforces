#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#define mid ((l+r)>>1)
using namespace std;
const int maxn=5010;
int n;
int a[maxn],ans[maxn],pre[maxn];
map <int,int> mp;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=res*10+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
int main(){
	n=read();
	for(register int i=1,x;i<=n;++i){
		a[i]=read();
		x=abs(a[i]);
		for(register int j=2;j*j<=x;++j)
			while(a[i]%(j*j)==0)a[i]/=j*j;
		pre[i]=mp[a[i]];
		mp[a[i]]=i;
	}
	for(register int i=1;i<=n;++i){
		for(register int j=i,d=0;j<=n;++j){
			if(!a[j]){
				if(!d)++ans[1];
				else ++ans[d];
				continue;
			}
			else if(pre[j]<i)
				++d;
			++ans[d];
		}
	}
	for(register int i=1;i<=n;++i)
		printf("%d ",ans[i]);
    return 0;
}