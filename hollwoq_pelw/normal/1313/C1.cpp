#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int Q=1<<20;
int st[Q];
int a[Q];
ll rem[Q];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int top=0;
	st[top]=0;
	ll sm=0;
	for(int i=1;i<=n;i++){
		while(a[i]<=a[st[top]])
			sm-=1LL*a[st[top]]*(st[top]-st[top-1]),--top;
		sm+=1LL*a[i]*(i-st[top]);
		rem[i]=sm-a[i];
		st[++top]=i;
	}
	top=0;
	st[top]=n+1;
	sm=0;
	int pos=0;
	ll mx=-1e18;
	for(int i=n;i;--i){
		while(a[i]<=a[st[top]])
			sm-=1LL*a[st[top]]*(st[top-1]-st[top]),--top;
		sm+=1LL*a[i]*(st[top]-i);
		st[++top]=i;
		if(sm+rem[i]>mx)mx=sm+rem[i],pos=i;
	}
	for(int i=pos-1;i;--i)
		a[i]=min(a[i],a[i+1]);
	for(int i=pos+1;i<=n;i++)
		a[i]=min(a[i],a[i-1]);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}