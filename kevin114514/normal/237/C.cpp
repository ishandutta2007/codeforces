#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<bitset>
#include<utility>
#include<algorithm>
#include<functional>
#include<ctime>
#include<cmath>
#include<cstdlib>
#include<cstdio>
using namespace std;
int isnp[2002000];
void prime(int n)
{
	isnp[0]=isnp[1]=true;
	for(int i=2;i<=n;i++)
		if(!isnp[i])
			for(int j=2*i;j<=n;j+=i)
				isnp[j]=true;
	for(int i=1;i<=2*n;i++)
		isnp[i]+=isnp[i-1];
	return ;
}
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	prime(m);
	int Low=k,High=m-n+1;
	while(Low<High)
	{
		int l=(Low+High)/2;
		int tmp=l-k,flag=1;
		for(int i=n;i<=m-l+1;i++)
			if(isnp[i+l-1]-isnp[i-1]>tmp)
			{
				flag=0;
				break;
			}
		if(flag)
			High=l;
		else	Low=l+1;
	}
	int tmp=Low-k,flag=1;
	for(int i=n;i<=m-Low+1;i++)
		if(isnp[i+Low-1]-isnp[i-1]>tmp)
		{
			flag=0;
			break;
		}
	cout<<(flag&&Low==High?Low:-1)<<endl;
	return 0;
}