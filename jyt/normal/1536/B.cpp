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
#define N 1005
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,n,A[N];
char s[N];
void Solve()
{
	A[0]=-1;
	for(int i=1;i<=n;i++) A[i]=s[i]-'a';
	std::sort(A+1,A+1+n),A[n+1]=26;
	for(int i=1;i<=n+1;i++)
		if(A[i]>A[i-1]+1) {printf("%c\n",A[i-1]+1+'a');return;}
	if(n==1) {puts("aa");return;}
	for(int i=1;i<n;i++) A[i]=(s[i]-97)*26+s[i+1]-97;
	std::sort(A+1,A+n),A[n]=676;
	for(int i=1;i<=n;i++)
		if(A[i]>A[i-1]+1) {printf("%c%c\n",(A[i-1]+1)/26+'a',(A[i-1]+1)%26+'a');return;}
	if(n==2) {puts("aaa");return;}
	for(int i=1;i<n-1;i++) A[i]=(s[i]-97)*26*26+(s[i+1]-97)*26+s[i+2]-97;
	std::sort(A+1,A+n-1),A[n-1]=17576;
	for(int i=1;i<n;i++)
		if(A[i]>A[i-1]+1) {printf("%c%c%c\n",(A[i-1]+1)/26/26+'a',(A[i-1]+1)/26%26+'a',(A[i-1]+1)%26+'a');return;}
}
int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%d%s",&n,s+1);
		Solve();
	}
	return 0;
}
/*
1
52
abacadaeafagahaiajakalamanaoapaqarasatauavawaxayazaa
*/