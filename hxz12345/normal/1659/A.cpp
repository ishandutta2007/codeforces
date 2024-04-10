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
	int j,A,B,i,n,r,b;
	n=read();r=read();b=read();
	A=r/(b+1);
	B=r%(b+1);
	if(0<B){
		for (j=1;j<=A+1;j++) printf("R");
	}else{
		for (j=1;j<=A;j++) printf("R");
	}
	for (i=1;i<=b;i++)
	    {
	    	printf("B");
	    		if(i<B){
		for (j=1;j<=A+1;j++) printf("R");
	}else{
		for (j=1;j<=A;j++) printf("R");
	}
		}puts("");
}
int main(){
	int Testing=read();
	for (;Testing;Testing--) Main();
return 0;
}