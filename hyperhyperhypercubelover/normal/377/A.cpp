#include<cstdio>

char a[1000][1000];
bool v[1000][1000];
int n,m,k;

void f(int x,int y)
{
if(x<0||x>=n||y<0||y>=m||a[x][y]!='.'||v[x][y])return;
v[x][y]=true;
f(x+1,y);
f(x-1,y);
f(x,y+1);
f(x,y-1);
if(k)
{
a[x][y]='X';
k--;
}
}

int main()
{
int i,j;
scanf("%d%d%d",&n,&m,&k);
for(i=0;i<n;i++)scanf("%s",a[i]);
for(i=0;i<n;i++){for(j=0;j<m;j++)if(a[i][j]=='.')break;if(j<m)break;}
f(i,j);
for(i=0;i<n;i++)puts(a[i]);
}