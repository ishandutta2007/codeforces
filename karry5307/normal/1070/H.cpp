#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
unordered_map<string,pair<ll,string> >mp;
unordered_map<string,ll>mp2;
ll n,qcnt;
string s;
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
inline void calcHash(string s)
{
	ll len=s.length();
	string t;
	mp2.clear();
	for(register int i=0;i<len;i++)
	{
		t="";
		for(register int j=i;j<len;j++)
		{
			t+=s[j];
			if(!mp2[t])
			{
				mp.find(t)==mp.end()?mp[t].second=s,1:1,mp[t].first++,mp2[t]=1;
			}
		}
	}
}
int main()
{
	n=read();
	for(register int i=1;i<=n;i++)
	{
		cin>>s,calcHash(s);	
	}	
	qcnt=read();
	for(register int i=1;i<=qcnt;i++)
	{
		cin>>s;
		if(mp.find(s)==mp.end())
		{
			puts("0 -");
			continue;
		}
		cout<<mp[s].first<<" "<<mp[s].second<<endl;
	}
}