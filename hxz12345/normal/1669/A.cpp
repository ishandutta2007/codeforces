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
long long n;
void Main(){
 n=read();
 if (n>=1900) puts("Division 1");
 else 
 if (n>=1600) puts("Division 2");
 else 
 if (n>=1400) puts("Division 3");
 else puts("Division 4");
}
int main()
{
	int Testing=read();
	for (;Testing;Testing--) Main();
return 0;
}