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
long long pow(long long x,long long y,long long p)
{
	long long ans=1;
	for (;y;y>>=1,x=x*x % p)
		if (y&1) ans=ans*x % p;
	return ans;
}
long long gcd(long long x,long long y)
{
	if (y==0) return x;
	long long ans=gcd(y,x % y);return ans;
}
int kk,y,ans,n,m,lft,rit,x,aa,lst,i,j,now;
bool exist[1010100];
int main()
{
	ios::sync_with_stdio(0);cin.tie();cout.tie();
	cin>>n>>m;
	if (n % m==0)   
	    {
	    	for (i=1;i<=n/m;i++)
	    	     {
	    	     	cout<<"?";
	    	     	for (j=(i-1)*m+1;j<=i*m;j++) cout<<" "<<j;
	    	     	cout<<endl;
	    	     	cin>>x;
	    	     	ans=ans^x;
	    	     	cout.flush();
				 }
			cout<<"! "<<ans<<endl;cout.flush();
	    	return 0;
		}
	x=(n/m-1);y=n-x*m;
	if (x==0) kk=y-m;else 
	    {
	    	if (y%2==0) kk=y;
	    	else kk=y-m;
		}
	if ((kk % 2!=0)&&(y%2!=0)) 
	     {
	     	puts("-1");return 0;
		 }
	
	lst=n;
	for (i=n/m;i>=(n/m)-x+1;i--)
	    	     {
	    	     	cout<<"?";
	    	     	for (j=lst;j>=lst-m+1;j--) cout<<" "<<j;
	    	     	cout<<endl;cout.flush();
	    	     	cin>>aa;lst-=m;
	    	     	ans=ans^aa;
				 }
		//1 2 3
		// 
		//
		//6 4 a[1] a[2] a[3] a[4] a[2] a[3] a[4] a[5] 
		//x=m-y m-y+m-y=n-m
		//(3*m-n)/2=y
		//2m-n=2y
		//
	if (kk%2==0)
	     {
	     	if (kk==y-m)
	     	   {
	     	x=(3*m-y)/2;
	     	cout<<"?";
	     	for (i=1;i<=m;i++) cout<<" "<<i;
	     	cout<<endl;cin>>aa;ans^=aa;cout.flush();cout<<"?";
	     	for (i=m-x+1;i<=2*m-x;i++) cout<<" "<<i;
	     	cout<<endl;cin>>aa;ans^=aa;cout.flush();
            cout<<"?";
	     	for (i=m-x+1;i<=m;i++) cout<<" "<<i;
			 for (i=2*m-x+1;i<=y;i++) cout<<" "<<i;
			 cout<<endl;cin>>aa;ans^=aa;cout.flush();
			 cout<<"! "<<ans<<endl;cout.flush(); 
	     	return 0;
	           }
	    else
	         {
	         	x=(3*m-(y+m))/2;
	         	cout<<"?";
	         	for (i=n-x+1;i<=n;i++) cout<<" "<<i;
	         	for (i=1;i<=m-x;i++) cout<<" "<<i;
	     	cout<<endl;cin>>aa;ans^=aa;cout.flush();cout<<"?";
	         	for (i=n-x+1;i<=n;i++) cout<<" "<<i;
	         	for (i=m-x+1;i<=m-x+1+(m-x)-1;i++) cout<<" "<<i;
	         	
	     	cout<<endl;cin>>aa;ans^=aa;cout.flush();
	     	cout<<"! "<<ans<<endl;
	         	return 0;
			 }
		 }
	for (i=1;i<=y/((y-m)*2);i++)
	      {
	      	lft=(i-1)*((y-m)*2)+1;rit=i*(y-m)*2;
	      	for (j=1;j<=y;j++) exist[j]=false;
	      	for (j=lft;j<=rit;j++) exist[j]=true;
	      	cout<<"?";
	      	for (j=lft;j<=lft+(y-m)-1;j++) cout<<" "<<j;
	      	x=m-(y-m);
	      	for (j=1;j<=y;j++)
	      	   if (exist[j]==false)
	      	        {
	      	        	if (x==0) break;
	      	        	cout<<" "<<j;
	      	        	x--;
					  }
			cout<<endl;cin>>aa;ans^=aa;cout.flush();
			cout<<"?";
			for (j=lft+(y-m);j<=rit;j++) cout<<" "<<j;
	      	x=m-(y-m);
	      	for (j=1;j<=y;j++)
	      	   if (exist[j]==false)
	      	        {
	      	        	if (x==0) break;
	      	        	cout<<" "<<j;
	      	        	x--;
					  }
			cout<<endl;cin>>aa;ans^=aa;cout.flush();
		  }
	now=y-(y/((y-m)*2)*((y-m)*2));lst=y-now;
	if (now==0)
	     {
	     	cout<<"! "<<ans<<endl;cout.flush();
	     	return 0;
		 }
	for (i=1;i<=lst;i++) exist[i]=false;
	cout<<"?";
	for (i=lst+1;i<=y;i++) exist[i]=true;
	for (i=lst+1;i<=lst+(now/2);i++) cout<<" "<<i;
	x=m-(now)/2;
	      	for (j=1;j<=y;j++)
	      	   if (exist[j]==false)
	      	        {
	      	        	if (x==0) break;
	      	        	cout<<" "<<j;
	      	        	x--;
					  }
	cout<<endl;cin>>aa;ans^=aa;cout.flush();
	cout<<"?";
	for (i=lst+(now/2)+1;i<=y;i++) cout<<" "<<i;
	x=m-(now)/2;
	      	for (j=1;j<=y;j++)
	      	   if (exist[j]==false)
	      	        {
	      	        	if (x==0) break;
	      	        	cout<<" "<<j;
	      	        	x--;
					  }
	cout<<endl;cin>>aa;ans^=aa;cout.flush();
	cout<<"! "<<ans<<endl;cout.flush();
return 0;
}