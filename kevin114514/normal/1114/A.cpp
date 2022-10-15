#include<bits/stdc++.h>
using namespace std;
inline void die()
{
	puts("NO");
	exit(0);
}
int main()
{
	int x,y,z,a,b,c;
	cin>>x>>y>>z>>a>>b>>c;
	if(a<x)
		die();
	a-=x;
	int tmp=a+b;
	if(tmp<y)
		die();
	tmp-=y;
	int tmp1=tmp+c;
	if(tmp1<z)
		die();
	puts("YES");
	return 0;
}