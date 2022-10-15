#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+10;
int digits[MAXN],base,k,ans=0;
int main()
{
	scanf("%d%d",&base,&k);
	for(int i=0;i<k;i++)
		scanf("%d",&digits[i]);
	ans=abs(digits[k-1]%2);
	if(base%2!=0)
		for(int i=k-2;i>=0;i--)
		{
			int tmp=abs(digits[i]%2);
			ans=abs(ans-tmp);
		}
	printf(ans==0?"even":"odd");
	return 0;
}