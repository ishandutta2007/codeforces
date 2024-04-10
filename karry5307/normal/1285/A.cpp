#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1;
string str;
ll length,l,r;
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
	length=read();
	cin>>str;
	for(register int i=0;i<length;i++)
	{
		str[i]=='L'?l++:r++;
	}
	printf("%d\n",l+r+1);
}