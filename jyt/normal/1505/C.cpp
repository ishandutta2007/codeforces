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
int n;
char s[N];
int main()
{
	scanf("%s",s+1),n=strlen(s+1);
	for(int i=3;i<=n;i++)
	{
		if(s[i]-65!=(s[i-1]+s[i-2])%26) return puts("NO"),0;
	}
	puts("YES");
	return 0;
}