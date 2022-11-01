#include <bits/stdc++.h>
#define rdst(st,len) {char ss[len];scanf("%s",ss);(st)=ss;}
using namespace std;
int n,m,i,j,a[500005];
string s,t;
int main()
{
	scanf("%d%d",&n,&m);
	rdst(s,n+5);rdst(t,m+5);
	if (((int)(s.find("*")))==-1)
	{
		if (s==t) puts("YES"); else puts("NO");
		return 0;
	}
	if (n-1>m)
	{
		puts("NO");
		return 0;
	}
	for (i=0;i<n&&i<m&&s[i]==t[i];i++);
	for (j=0;j<n&&j<m&&s[n-j-1]==t[m-j-1];j++);
	if (i+j+1==n) puts("YES"); else puts("NO");
	return 0;
}