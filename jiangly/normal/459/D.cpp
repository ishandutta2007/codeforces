#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e6+5;
int n;
int a[N],pre[N],suf[N],t[N];
LL ans;
map<int,int>s;
int lowbit(int x){
	return x&-x;
}
void add(int x,int y){
	while(x<=n){
		t[x]=t[x]+y;
		x=x+lowbit(x);
	}
}
int sum(int x){
	int ans=0;
	while(x){
		ans=ans+t[x];
		x=x-lowbit(x);
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",a+i);
	}
	for(int i=1;i<=n;++i){
		++s[a[i]];
		pre[i]=s[a[i]];
	}
	s.clear();
	for(int i=n;i;--i){
		++s[a[i]];
		suf[i]=s[a[i]];
	}
	for(int i=n;i;--i){
		ans=ans+sum(pre[i]-1);
		add(suf[i],1);
	}
	printf("%lld",ans);
	return 0;
}