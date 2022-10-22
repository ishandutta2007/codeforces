#include<bits/stdc++.h>
using namespace std;
const int M=1e6+9;
int n,top1,top2;
int a[M],s[M],t[M];
long long ans=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		while(top1&&a[s[top1]]>a[i])ans-=1ll*(i-s[top1])*(s[top1]-s[top1-1])*a[s[top1]],top1--;
		while(top2&&a[t[top2]]<a[i])ans+=1ll*(i-t[top2])*(t[top2]-t[top2-1])*a[t[top2]],top2--;
		s[++top1]=i;
		t[++top2]=i;
	}
	while(top1)ans-=1ll*(n+1-s[top1])*(s[top1]-s[top1-1])*a[s[top1]],top1--;
	while(top2)ans+=1ll*(n+1-t[top2])*(t[top2]-t[top2-1])*a[t[top2]],top2--;
	printf("%lld\n",ans);
	return 0;
}