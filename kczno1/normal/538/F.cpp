#include<bits/stdc++.h>
using namespace std;

#define gc (c=getchar())
int read()
{
	char c;
	while(gc<'-');
	if(c=='-')
	{
		int x=gc-'0';
	    while(gc>='0')x=x*10+c-'0';
	    return -x;
	}
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}
const int N=2e5+5;
int a[N],s[N];

int main()
{
	//freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
	int n=read();
	for(int i=0;i<n;++i)
	{
	  int x=a[i]=read();
	  int k=1,v=i-1;
	  while(k<=v)
	  {
	  	 int pv=v/k;
	 	 int _k=v/pv+1;
	 	 if(x<a[pv]) { ++s[k];--s[_k]; }
	 	 k=_k;
	  }
	  if(x<a[0]) ++s[k];
	}
	for(int i=1;i<n;++i) 
	{
		s[i]+=s[i-1];
		printf("%d ",s[i]);
	}
}