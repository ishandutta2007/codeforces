#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
vector<string>v;
ll n;
ll mp[8];
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
	n=read();
	for(register int i=1;i<=n;i++)
	{
		mp[read()]++;
	}
	while(mp[1]&&mp[2]&&mp[4])
	{
		v.push_back("1 2 4"),mp[1]--,mp[2]--,mp[4]--;
	}
	while(mp[1]&&mp[3]&&mp[6])
	{
		v.push_back("1 3 6"),mp[1]--,mp[3]--,mp[6]--;
	}
	while(mp[1]&&mp[2]&&mp[6])
	{
		v.push_back("1 2 6"),mp[1]--,mp[2]--,mp[6]--;
	}
	if(v.size()!=n/3)
	{
		return puts("-1"),0;
	}
	for(auto i:v)
	{
		cout<<i<<endl;
	}
}