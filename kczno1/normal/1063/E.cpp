#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=1000+5;
char s[N][N];
int a[N];bool vis[N];
int top=1;
void add(int j,int k)
{
	if(k>j){s[top][j]='/';s[top][k]='/';}
	else{s[top][j]='\\';s[top][k]='\\';}
	++top;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	int n;cin>>n;
	rep(i,1,n)cin>>a[i];
	rep(i,1,n)
	rep(j,1,n)s[i][j]='.';
	bool ans_n=1;
	rep(i,1,n)ans_n&=a[i]==i;
	if(ans_n)
	{
		printf("%d\n",n);
		rep(i,1,n)printf("%s\n",s[i]+1);
		exit(0);
	}
	int j=1;
	while(a[j]!=1)
	{
		j=a[j];vis[j]=1;
		add(j,a[j]);
	}
	rep(i,2,n)
	if(!vis[i])
	{
		if(a[i]==i)continue;
		s[top][1]='/';
		int j=i;
		while(a[j]!=i)
		{
			add(j,a[j]);
			j=a[j];vis[j]=1;
		}
		add(j,1);
	}
	printf("%d\n",n-1);
	rep(i,1,n)printf("%s\n",s[i]+1);
}