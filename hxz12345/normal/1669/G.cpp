#include<bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
char a[1010][1010];
int n,m,b,i,j;
void Main(){
	cin>>n>>m;
		for(i=1;i<=n;i=i+1)cin>>a[i]+1;
		for(i=1;i<=m;i=i+1)
		{
			for(j=n;j>=1;j=j-1)
			{
				if(a[j][i]=='*')
				{
					for(b=j+1;b<=n;b=b+1)
					if(a[b][i]=='.'&&a[b-1][i]=='*')swap(a[b-1][i],a[b][i]);
				}
			}
		}
		for(i=1;i<=n;i=i+1)cout<<a[i]+1<<endl;
	}
int main()
{
	int Testing=read();
	for (;Testing;Testing--) Main();
return 0;
}