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
long long n,tn,x;
bool flag;
void Main(){
	n=read();
	//6=2*3
	//12=4*3
	//k*a+k*b+...+k.c+k*(k-1)/2=n
	//(30-3) % 3=0
	//9+9+1+9+2=
	//2*k
	//(2n-k*k+k) % 2k=0
	//
	//=tn;
	tn=n;
	x=1;flag=false;
	while (x<=n){
		if (tn % 2==0) tn/=2;
		if (x!=1)	
		if (x<=sqrt(2*n))
		    if (n>=x*(x-1)/2)
		    if ((n-x*(x-1)/2) % x==0){
		    	printf("%lld\n",x);return ;
			}
		x=x*2;
	}//22=4+5+6+7
	if (tn!=1)
	if (tn<=sqrt(2*n))
	    if (n>=tn*(tn-1)/2)
	     if ((n-tn*(tn-1)/2) % tn==0){
	     	printf("%lld\n",tn);
	     	return ;
		 }
	puts("-1");
	
return ;
}
int main()
{
 int Testing=read();
 for (;Testing;Testing--) Main();
 return 0;
}