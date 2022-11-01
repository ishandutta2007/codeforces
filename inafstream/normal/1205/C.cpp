#include <bits/stdc++.h>
using namespace std;

int n,m,i,j,a[55][55],fa[5005],x;

int id(int x,int y)
{
	return (x-1)*n+y;
}
int fnd(int x)
{
	if (fa[x]==x) return x;
	return fa[x]=fnd(fa[x]); 
}
int sta(int x,int y)
{
	if (fnd(x)==fnd(y))return 1;
	if (fnd(x)==fnd(y+n*n))return -1;
	return 0;
}

void print()
{
	puts("!");
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			printf("%d",a[i][j]);
		}
		puts("");
	}
	fflush(stdout);
}

string st;
bool check(string st)
{
	string ts=st;
	reverse(ts.begin(),ts.end());
	return st==ts;
}
bool dfs(int lx,int ly,int rx,int ry,int f)
{
	st.push_back(a[lx][ly]+48);
	if(lx==rx&&ly==ry)
	{
//		cerr<<rx<<' '<<ry<<' '<<st<<endl;
		if(check(st)==f){
			st.erase(st.size()-1);
			return 1;
		}
		st.erase(st.size()-1);
		return 0;
	}
	if(lx<rx&&dfs(lx+1,ly,rx,ry,f)){
		st.erase(st.size()-1);
		return 1;
	}
	if(ly<ry&&dfs(lx,ly+1,rx,ry,f)){
		st.erase(st.size()-1);
		return 1;
	}
	st.erase(st.size()-1);
	return 0;
}

int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	scanf("%d",&n);
	for (i=1;i<=n*n*2;i++)
	{
		fa[i]=i;
	}
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			if (i+2<=n&&!sta(id(i,j),id(i+2,j)))
			{
				if((i+2)*j==n*n)continue;
				printf("? %d %d %d %d\n",i,j,i+2,j);
				fflush(stdout);
				scanf("%d",&x);
				if (x)
				{
					fa[fnd(id(i,j))]=fnd(id(i+2,j));
					fa[fnd(id(i,j)+n*n)]=fnd(id(i+2,j)+n*n);
				}
				else
				{
					fa[fnd(id(i,j))]=fnd(id(i+2,j)+n*n);
					fa[fnd(id(i,j)+n*n)]=fnd(id(i+2,j));
				}
			}
			if (j+2<=n&&!sta(id(i,j),id(i,j+2)))
			{
				if((i)*(j+2)==n*n)continue;
				printf("? %d %d %d %d\n",i,j,i,j+2);
				fflush(stdout);
				scanf("%d",&x);
				if (x)
				{
					fa[fnd(id(i,j))]=fnd(id(i,j+2));
					fa[fnd(id(i,j)+n*n)]=fnd(id(i,j+2)+n*n);
				}
				else
				{
					fa[fnd(id(i,j))]=fnd(id(i,j+2)+n*n);
					fa[fnd(id(i,j)+n*n)]=fnd(id(i,j+2));
				}
			}
			if (i+1<=n&&j+1<=n&&!sta(id(i,j),id(i+1,j+1)))
			{
				if((i+1)*(j+1)==n*n)continue;
				printf("? %d %d %d %d\n",i,j,i+1,j+1);
				fflush(stdout);
				scanf("%d",&x);
				if (x)
				{
					fa[fnd(id(i,j))]=fnd(id(i+1,j+1));
					fa[fnd(id(i,j)+n*n)]=fnd(id(i+1,j+1)+n*n);
				}
				else
				{
					fa[fnd(id(i,j))]=fnd(id(i+1,j+1)+n*n);
					fa[fnd(id(i,j)+n*n)]=fnd(id(i+1,j+1));
				}
			}
		}
	}
	
	memset(a,-1,sizeof(a));
	a[1][1]=1;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			if ((i+j)%2==0)
			{
				if(sta(id(i,j),id(1,1))==1) a[i][j]=a[1][1];
				else a[i][j]=!a[1][1]; 
			}
		}
	}
	
	int fx=0,fy=0;
	for (i=1;i<=n-2;i++)
	{
		for (j=1;j<=n-2;j++)
		{
			if ((i+j)%2==0)
			{
				if(a[i][j]==1&&a[i+2][j+2]==0)
				{
					fx=i;fy=j;
				}
			}
		}
	}
	if(!fx||!fy) exit(-2);
	
	fx--;fy--;
	int f1123,f1132,f1233;
	printf("? %d %d %d %d\n",fx+1,fy+1,fx+2,fy+3);
	fflush(stdout);
	scanf("%d",&f1123);
	printf("? %d %d %d %d\n",fx+1,fy+1,fx+3,fy+2);
	fflush(stdout);
	scanf("%d",&f1132);
	printf("? %d %d %d %d\n",fx+1,fy+2,fx+3,fy+3);
	fflush(stdout);
	scanf("%d",&f1233);
	
	a[1][2]=1;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			if ((i+j)%2==1)
			{
				if(sta(id(i,j),id(1,2))==1) a[i][j]=a[1][2];
				else a[i][j]=!a[1][2]; 
			}
		}
	}
	if(dfs(fx+1,fy+1,fx+2,fy+3,f1123)&&dfs(fx+1,fy+1,fx+3,fy+2,f1132)&&dfs(fx+1,fy+2,fx+3,fy+3,f1233))
	{
		print();
		return 0;
	}
	
	a[1][2]=0;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=n;j++)
		{
			if ((i+j)%2==1)
			{
				if(sta(id(i,j),id(1,2))==1) a[i][j]=a[1][2];
				else a[i][j]=!a[1][2]; 
			}
		}
	}
//	cerr<<st<<endl;
	if(dfs(fx+1,fy+1,fx+2,fy+3,f1123)&&dfs(fx+1,fy+1,fx+3,fy+2,f1132)&&dfs(fx+1,fy+2,fx+3,fy+3,f1233))
	{
		print();
		return 0;
	}
	
	exit(-1);
}