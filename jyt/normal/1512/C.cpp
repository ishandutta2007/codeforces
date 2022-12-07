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
#define N 200005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,a,b;
char s[N];
void Solve()
{
	int tot=0;n=strlen(s+1);
	if(a+b!=n) {puts("-1");return;}
	for(int i=1,j=n;i<j;i++,j--)
	{
		if(s[i]!='?'&&s[j]!='?'&&s[i]!=s[j]) {puts("-1");return;}
		if(s[i]=='0'||s[j]=='0') a-=2,s[i]=s[j]='0';
		if(s[i]=='1'||s[j]=='1') b-=2,s[i]=s[j]='1';
		if(s[i]=='?'&&s[j]=='?') tot+=2;
	}
	if(n&1)
	{
		if(s[n+1>>1]=='0') a--;
		if(s[n+1>>1]=='1') b--;
		if(s[n+1>>1]=='?') tot++;
	}
	if(a<0||b<0||a+b!=tot||a&1&&b&1) {puts("-1");return;}
	// dbg1(a),dbg1(b),dbg2(tot);
	// printf("%s\n",s+1);
	for(int i=1,j=n;i<=j;i++,j--)
	{
		if(s[i]!='?') continue;
		if(i==j) {s[i]=a?'0':'1';break;}
		// dbg1(i),dbg1(j),dbg1(a),dbg2(b);
		if(a>1) s[i]=s[j]='0',a-=2;
		else s[i]=s[j]='1',b-=2;
	}
	printf("%s\n",s+1);
}
int main()
{
	for(scanf("%d",&T);T--;) scanf("%d%d%s",&a,&b,s+1),Solve();
	return 0;
}