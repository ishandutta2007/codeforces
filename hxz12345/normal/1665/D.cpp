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
long long i,ans,G;
void Main(){
	ans=0;
	for (i=0;i<=29;i++)
	    {
	    	cout<<"? "<<((1ll<<i)-ans)<<" "<<(1ll<<(i+1))+(1ll<<i)-ans<<endl;
	    	cout.flush();
	        cin>>G;
	    	if (G&(1ll<<(i+1))) ans+=(1ll<<i);
		}
    cout<<"! "<<ans<<endl;
    cout.flush();
}
int main()
{	int Testing=read();
	for (;Testing;Testing--) Main();
return 0;
}
//a>b
//gcd(x+a,x+b)=gcd(x+b,(x+a) % (x+b))=gcd(x+b,a-b)
//gcd(x+b,a-b)=
//gcd(a-b,x+b-a+b)=gcd(a-b,x+2b-a)=gcd(x+2b-a,a-b) 
//gcd(x+1,2) 
//gcd(x+a,b) a,b>0 
//gc(x+1,2)=
//gcd(x+1,4)
//gcd(b,x+a) gcd(x+1,b)bx+1
//gcd(x+2^y,x+2^{y+1})=gcd(x+2^{y+1},x+2^y)=gcd(x+2^{y},2^y) 
//gcd(x+2,x+1)=gcd(x+1,1)
//gcd(x+4,x+2)=gcd(x+2,2)
//gcd(