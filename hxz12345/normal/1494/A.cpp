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
long long n,a[10010],Testing,i;
bool flag;
string s;
void sc(int x,int K)
{
	int i;
	if (x>3)
	   { 
	   int AA=0;
	   for (i=1;i<=n;i++)
	       {
	       	if (a[s[i-1]-'A'+1]==1) AA++;
	       	else AA--;
	       	if (AA<0) return ;
		   }
	if (AA!=0) return ;
	flag=true;
	   return ;
	   }
	a[x]=1;
	sc(x+1,K+1);
	a[x]=0;
	sc(x+1,K);
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie();cout.tie();
	cin>>Testing;
	for (;Testing;Testing--)
	        {
	        cin>>s;n=s.size();flag=false;
	        sc(1,0);
	        if (flag) puts("YES");
	        else puts("NO");
			}
		return 0;
}