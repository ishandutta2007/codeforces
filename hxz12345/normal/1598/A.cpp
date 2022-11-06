#include <bits/stdc++.h>
using namespace std;
inline long long read()
{
  long long x=0,f=1;char ch=getchar();
  while(!isdigit(ch)&&ch!='-')ch=getchar();
  if(ch=='-')f=-1,ch=getchar();
  while(isdigit(ch))x=(x<<1)+(x<<3)+ch-'0',ch=getchar();
  return x*f;
}
bool exist[3][2000];
long long j,a[3][20000],Testing,n,i;
string S,T;
void sc(int x,int y)
{
   if (exist[x][y]) return ;
   exist[x][y]=true;
   if ((x+1<=2)&&(y+1<=n)&&(a[x+1][y+1]==0)) sc(x+1,y+1);
   if ((x+1<=2)&&(y<=n)&&(a[x+1][y]==0)) sc(x+1,y);
   if ((x<=2)&&(y+1<=n)&&(a[x][y+1]==0)) sc(x,y+1);
   if ((x-1>=1)&&(y+1<=n)&&(a[x-1][y+1]==0)) sc(x-1,y+1);
   if ((x-1>=1)&&(y<=n)&&(a[x-1][y]==0)) sc(x-1,y);
}
int main()
{
    Testing=read();
    for (;Testing;Testing--)
       { 
       n=read();
       cin>>S;
       cin>>T;
       for (i=1;i<=n;i++) a[1][i]=S[i-1]-'0',a[2][i]=T[i-1]-'0';
       for (i=1;i<=2;i++)
         for (j=1;j<=n;j++)
             exist[i][j]=false;
       sc(1,1);
       if (exist[2][n]) puts("YES");
       else puts("NO");
	   }
	return 0;
}