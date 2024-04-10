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
int l,r,mid,ans,n,G,i,x;
int find(int mid){
	cout<<"? "<<mid<<endl;
	cin>>x;
	cout.flush();
	return x;
}
int main()
{
	n=read();
	l=1;r=4002000;
	while (l<=r){
		mid=(l+r)>>1;
		if (find(mid)==1) ans=mid,r=mid-1;
		else l=mid+1;
	}
	G=ans;
	for (i=2;i<=n;i++)
	    {
	    	cout<<"? "<<((ans-1)/i)<<endl;
	    	cin>>x;
	    	cout.flush();
	    	if (x>0) G=min(G,((ans-1)/i)*x);
		}
	cout<<"! "<<G<<endl;
return 0;
}