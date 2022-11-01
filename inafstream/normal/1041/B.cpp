#include <bits/stdc++.h>
#define rdst(st,len) {char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
long long a,b,c,d,e;
int main()
{
	cin>>a>>b>>c>>d;
	e=__gcd(c,d);
	c/=e;d/=e;
	cout<<min(a/c,b/d)<<endl;
	return 0;
}