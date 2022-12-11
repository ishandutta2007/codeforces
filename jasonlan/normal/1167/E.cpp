#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
const int maxn=1010000;
int n,x;
int a[maxn],maxv[maxn],minv[maxn];
long long ans;
set<int> s;
inline int read(){
	int res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
int main(){
	n=read();x=read();
	for(register int i=0;i<=x;++i)
		minv[i]=x+1;
	for(register int i=1,maxx=0;i<=n;++i){
		a[i]=read();
		if(maxx>a[i]){
			maxv[a[i]]=max(maxv[a[i]],maxx);
			minv[a[i]]=min(minv[a[i]],*s.upper_bound(a[i]));
		}
		maxx=max(maxx,a[i]);
		s.insert(a[i]);
	}
	//
	int r=x;
	while(r&&!maxv[r])--r;
	if(!r){
		printf("%lld\n",1ll*x*(x+1)/2);
		return 0;
	}
	for(register int l=0,minx=x+1;l<=x&&l<minx;++l){
		minx=min(minx,minv[l]);
		r=max(r,maxv[l]);
		ans+=x-r+1;
	}
	printf("%lld\n",ans);
	return 0;
}