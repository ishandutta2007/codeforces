#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
using std::cin;using std::cerr;
using std::max;using std::min;
#define N 100005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int n,m,block,pos,ans;
int ask(int x) {printf("? %d\n",x),fflush(stdout),scanf("%d",&x);return x;}
int main()
{
	scanf("%d%d",&n,&m),block=(int)sqrt(n)/2;
	for(int i=1;i<=block+5;i++) ans=ask(pos=1);
	for(;ans==m;) pos+=block,ans=ask(pos);
	if(ans<m)
	{
		for(;ask((pos+block-1)%n+1)<m;) pos=(pos+block-1)%n+1;
		for(;ask(pos)<m;pos=pos<n?pos+1:1);
	}
	else
	{
		for(;ask((pos+n-block-1)%n+1)>m;) pos=(pos+n-block-1)%n+1;
		for(;ask(pos)>m;pos=pos>1?pos-1:n);
	}
	printf("! %d\n",pos);
	return 0;
}