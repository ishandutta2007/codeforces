#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,i,ss[111111];
int f(int x,int y,int z){printf("? %I64d %I64d %I64d\n",x,y,z);fflush(stdout);int xx;scanf("%I64d",&xx);return xx;}
int g(int a,int b,int c,int I64d){int w=f(a,b,c),x=f(a,b,I64d),y=f(a,c,I64d),z=f(b,c,I64d);return min(min(min(w,x),y),z)+max(max(max(w,x),y),z);}
signed main()
{
	scanf("%I64d",&n);
	int a=g(2,3,4,5),b=g(1,3,4,5),c=g(1,2,4,5),I64d=g(1,2,3,5),e=g(1,2,3,4);
	int m=(a+b+c+I64d+e)/4;a=m-a;b=m-b;c=m-c;I64d=m-I64d;e=m-e;
	for (i=6;i<=n;i++) ss[i]=g(1,2,3,i)-a-b-c;
	printf("! %I64d %I64d %I64d %I64d %I64d",a,b,c,I64d,e);for (i=6;i<=n;i++) printf(" %I64d",ss[i]);puts("");fflush(stdout);
	return 0;
}