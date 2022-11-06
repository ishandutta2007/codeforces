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
void Main(){
	int x,y;
	x=read();y=read();
int d=sqrt(x*x+y*y);
	if(x+y==0)cout<<0<<endl;
	else if(d*d==x*x+y*y)cout<<1<<endl;
	else cout<<2<<endl;
	return ;
}
int main()
{
	int Testing=read();
	for (;Testing;Testing--) Main();
 return 0;
}