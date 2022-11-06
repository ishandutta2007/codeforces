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
long long tag,G,i,n,a[1001010];
bool flag;
vector<int> exist;
void Main(){
	//1 2 3 4 5 6->6
	//6 1 2 3 4 5->1
	//5 6 1 2 3 4->2
	//
	n=read();exist.clear();
	for (i=1;i<=n;i++) a[i]=read();flag=true;tag=-1;
	for (i=1;i<=n;i++)
	    if (a[i]==1){tag=i;break;}
	if (tag==-1){puts("NO");return ;}
	for (i=tag;i<=n;i++) exist.push_back(a[i]);
	for (i=1;i<tag;i++) exist.push_back(a[i]);G=1;
	for (i=1;i<exist.size();i++)
	   {
	    if (exist[i]==1){puts("NO");return ;}
	    if (exist[i]==G+1) G++;
	    else 
		   {
		   if (exist[i]<=G) G=exist[i];
	    else {
	    	puts("NO");return ;
	    }
		}
	}
	puts("YES");
	// 
	return ;
}
int main()
{
	int Testing=read();
	for (;Testing;Testing--) Main();
 return 0;
}