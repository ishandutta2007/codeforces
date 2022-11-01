#include<bits/stdc++.h>
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
#define lwb lower_bound
#define upb upper_bound
using namespace std;
typedef int ll;
const ll MAXN=2e5+51;
string str;
ll qcnt,l,r,x;
ll occ[MAXN][26];
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
	cin>>str,qcnt=read(),occ[0][str[0]-'a']=1;
	for(register int i=1;i<str.length();i++)
	{
		for(register int j=0;j<26;j++)
		{
			occ[i][j]=occ[i-1][j];
		}
		occ[i][str[i]-'a']++;
	}
	for(register int i=0;i<qcnt;i++)
	{
		l=read()-1,r=read()-1,x=0;
		for(register int j=0;j<26;j++)
		{
			if(l==0)
			{
				x+=(bool)occ[r][j];
				continue;
			}
			if(occ[r][j]>occ[l-1][j])
			{
				x++;
			}
		}
		if(x>=3)
		{
			puts("Yes");
			continue;
		}
		puts((l==r||(x==2&&str[l]!=str[r]))?"Yes":"No");
	}
}