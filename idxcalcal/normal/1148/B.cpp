#include<bits/stdc++.h>
#define ri register int
using namespace std;
inline int read(){
	#define gc getchar
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
	#undef gc
}
typedef long long ll;
const int N=2e5+5;
int n,m,k,ta,tb,a[N],b[N];
int main(){
	n=read(),m=read(),ta=read(),tb=read(),k=read();
	if(k>=n||k>=m)return puts("-1"),0;
	for(ri i=1;i<=n;++i)a[i]=read();
	for(ri i=1;i<=m;++i)b[i]=read();
	int mx=k+1;
	for(ri i=1,j=1;i<=m;++i){
		while(j<n&&a[j]+ta<=b[i])++j;
		int x=a[j]+ta<=b[i]?j:j-1;
		if(k>=x)mx=max(mx,i+1+(k-x));
	}
	if(mx>m)return puts("-1"),0;
	cout<<b[mx]+tb;
	return 0;
}