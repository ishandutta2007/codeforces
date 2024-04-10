#include<iostream>
#include<cmath> 
#include<cstdio>

#define rep(i,j,k) for(i=j;i<=k;i++)
#define rrep(i,j,k) for(i=j;i>=k;i--)

using namespace std;

long n,i;
long long ans,tmp;
long a[600000],p[600000],q[600000];
long long b[600000],c[600000];

int main(){
	cin>>n;
	rep(i,1,n){
		scanf("%d",&a[i]);
	}
	b[0]=0;
	rep(i,1,n)
	  b[i]=b[i-1]+a[i];
	if (b[n]%3!=0){
		cout<<0<<endl;
		return 0;
	}
	else{
	tmp=b[n]/3;
	c[n+1]=0;
	rrep(i,n,1)
	  c[i]=c[i+1]+a[i];
	p[0]=0;
	rep(i,1,n)
	  if (b[i]==tmp)
	  	p[i]=p[i-1]+1;
	  else
	    p[i]=p[i-1];
	q[n+1]=0;
	rrep(i,n,1)
	  if (c[i]==tmp)
	  
	    q[i]=q[i+1]+1;
	  else
	    q[i]=q[i+1];
	ans=0;
	rep(i,1,n-2)
	if (b[i]==tmp){
	  ans+=q[i+2];
	}
	cout<<ans<<endl;
	return 0;
	}
}