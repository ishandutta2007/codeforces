#include<bits/stdc++.h>

using namespace std;

int n,ans,t,a[3000];

int main()
{
  cin>>n;
  ans=n+100;
  for(int i=0;i<n;i++)
    {
      cin>>a[i];
      if(a[i]==1) t++;
      int j=i-1,tmp=a[i];
      while(j>-1 && tmp>1)
	{
	  tmp=__gcd(tmp,a[j]);
	  j--;
	}
      if(tmp==1) ans=min(ans,i-j-1);
    }
  if(t>0) cout<<n-t<<endl;
  else if(ans>n) cout<<-1<<endl;
  else
    cout<<n-1+ans<<endl;
}