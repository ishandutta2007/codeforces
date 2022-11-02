#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
set<string>st;
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
int main()
{
	cin>>s;
	for(register int i=0;i<=s.length();i++)
	{
		for(register char j='a';j<='z';j++)
		{
			st.insert(s.substr(0,i)+j+s.substr(i));
		}
	}
	printf("%d\n",st.size());
}