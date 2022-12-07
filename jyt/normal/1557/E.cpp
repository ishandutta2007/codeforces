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
using std::string;
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n=8;string s;
void Solve()
{
	puts("1 1"),fflush(stdout);
	cin>>s;
	if(s=="Done") return;
	for(int i=1;i<n;i++)
	{
		for(int j=i>1?1:2;j<=n;j++)
		{
			printf("%d %d\n",i,j),fflush(stdout);
			cin>>s;
			if(s=="Done") return;
			if(s=="Up"||s=="Up-Left"||s=="Up-Right") j=j>1?0:1;
			if(s=="Down"||s=="Down-Right"||s=="Down-Left") i++,j--;
		}
		printf("%d %d\n",i+1,n),fflush(stdout);
		cin>>s;
		if(s=="Done") return;
	}
}
int main()
{
	for(scanf("%d",&T);T--;) Solve();
	return 0;
}