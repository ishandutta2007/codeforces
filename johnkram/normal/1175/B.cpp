#include<bits/stdc++.h>
using namespace std;
#define ll long long
char c[100];
ll s[100005];
int n,i,t;
void del()
{
	s[++t]=0;
	while(s[t-1]>=0)
	{
		s[t-1]+=s[t];
		t--;
		s[t]=min(s[t],1LL<<32);
	}
	s[t-1]*=-s[t];
	t--;
	s[t]=min(s[t],1LL<<32);
}
int main()
{
	scanf("%d",&n);
	s[++t]=-1;
	while(n--)
	{
		scanf("%s",c);
		if(c[0]=='a')s[++t]=1;
		else if(c[0]=='f')
		{
			scanf("%d",&i);
			s[++t]=-i;
		}
		else del();
	}
	del();
	if(s[1]==(1LL<<32))puts("OVERFLOW!!!");
	else cout<<s[1]<<endl;
	return 0;
}