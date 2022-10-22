// user:halahen
#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int i,j,k;
int read(){
	int tot=0,fh=1;
	char c=getchar();
	while ((c<'0')||(c>'9')){ if(c=='-') fh=-1; c=getchar(); }
	while ((c>='0')&&(c<='9')){ tot=tot*10+c-'0'; c=getchar(); }
	return tot*fh;
}
priority_queue<int> mp[maxn],c;
int n,m,a[maxn],b[maxn];
int r,d[maxn],ans,mx,tot[maxn];
int main(){
	n=read(); m=read();
	for (i=1;i<=n;i++){
		a[i]=read(); b[i]=read();
		mp[a[i]].push(b[i]);
	}
	for (i=1;i<=m;i++) c.push(i);
	mx=0; ans=0;
	while (c.size()!=0){
		r=0;
		while (c.size()!=0){
			r++; d[r]=c.top(); c.pop();
		}
		for (i=1;i<=r;i++){
			if (mp[d[i]].size()==0){
				if (tot[d[i]]>=0) ans=ans-tot[d[i]];
				d[i]=0;
			}
			else{
				if (tot[d[i]]>=0) ans=ans-tot[d[i]];
				tot[d[i]]=tot[d[i]]+mp[d[i]].top();
				if (tot[d[i]]>=0) ans=ans+tot[d[i]];
				mp[d[i]].pop();
			}
		}
		for (i=1;i<=r;i++){
			if (d[i]!=0){
				c.push(d[i]);
			}
		}
		mx=max(mx,ans);
	}
	printf("%d\n",mx);
	return 0;
}