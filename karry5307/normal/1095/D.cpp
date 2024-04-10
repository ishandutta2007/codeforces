#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=2e5+51;
ll cnt,curr;
ll cur[MAXN],pos[MAXN],num[MAXN][2],mp[MAXN][2];
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
inline void check()
{
	ll last=0,next,place;
	while(curr!=cnt)
	{
		next=mp[pos[curr-1]][mp[pos[curr-1]][0]==last];
		place=num[next][num[next][0]==pos[curr-1]];
		pos[curr++]=place;
		last=next;
	}
}
int main()
{
	cnt=read();
	for(register int i=0;i<cnt;i++)
	{
		num[i][0]=read(),num[i][1]=read(); 
		mp[num[i][0]][cur[num[i][0]]++]=i;
		mp[num[i][1]][cur[num[i][1]]++]=i;
	}
	pos[0]=num[0][0],pos[1]=num[0][1],curr=2;
	check();
	if(pos[cnt-1]!=1)
	{
		pos[0]=num[0][1],pos[1]=num[0][0],curr=2;
		check();
	}
	for(register int i=0;i<cnt;i++)
	{
		printf("%d ",pos[i]); 
	}
}