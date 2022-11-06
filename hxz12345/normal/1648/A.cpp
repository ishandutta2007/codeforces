#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
vector<pair<int,int>> V[100101];
long long now,n,m,i,j,x,w,a[1001010],suf[1001010],ans;
int main()
{
	n=read();m=read();
	for (i=1;i<=n;i++)
	    for (j=1;j<=m;j++){
	    	x=read();V[x].push_back(make_pair(i,j));
		}
	for (now=1;now<=100000;now++)
	     if (V[now].size()>0){
	     	w=0;
	     	for (i=0;i<V[now].size();i++) a[++w]=V[now][i].first;
	     	sort(a+1,a+w+1);
	     	suf[w+1]=0;
	     	for (i=w;i>=1;i--) suf[i]=suf[i+1]+a[i];
	     	for (i=1;i<w;i++) ans=ans+suf[i+1]-a[i]*(w-i);
	     	w=0;
	     	for (i=0;i<V[now].size();i++) a[++w]=V[now][i].second;
	     	sort(a+1,a+w+1);
	     	suf[w+1]=0;
	     	for (i=w;i>=1;i--) suf[i]=suf[i+1]+a[i];
	     	for (i=1;i<w;i++) ans=ans+suf[i+1]-a[i]*(w-i);
		 }
	printf("%lld\n",ans);
    return 0;
}