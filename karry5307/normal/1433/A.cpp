#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
unordered_map<ll,ll>mp={
	{1,1},{11,3},{111,6},{1111,10},
	{2,11},{22,13},{222,16},{2222,20},
	{3,21},{33,23},{333,26},{3333,30},
	{4,31},{44,33},{444,36},{4444,40},
	{5,41},{55,43},{555,46},{5555,50},
	{6,51},{66,53},{666,56},{6666,60},
	{7,61},{77,63},{777,66},{7777,70},
	{8,71},{88,73},{888,76},{8888,80},
	{9,81},{99,83},{999,86},{9999,90}
};
ll test;
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
    	neg=-1;
    	ch=getchar();
	}
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		printf("%d\n",mp[read()]);
	}
}