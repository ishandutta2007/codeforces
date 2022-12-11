#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int maxn=201000;
int n,deg[maxn],a[maxn];
priority_queue <int> q;
int main(){
	scanf("%d",&n);
	for(register int i=1,x;i<n;++i){
		scanf("%d",&a[i]);
		deg[a[i]]++;
	}
	printf("%d\n",a[1]);
	for(register int i=1;i<=n;++i)
		if(!deg[i])q.push(-i);
	for(register int i=n-1,p;i;--i){
		p=-q.top();q.pop();
		printf("%d %d\n",a[i],p);
		if(!(--deg[a[i]]))q.push(-a[i]);
	}
	return 0;
}