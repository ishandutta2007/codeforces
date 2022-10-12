
#include <iostream>
#include <string>

using namespace std;

int main()
{
  int l,n;
  cin>>n>>l;
  
  int a[100];
  int b[100];
  for(int i=0; i<n; i++)
  {cin>>a[i];}
  for(int i=0; i<n; i++)
  {cin>>b[i];}
  
  
 
  int tr=0;
  for(int k=0; k<n; k++) 
  {for(int i=0; i<l; i++)
  {
      tr=0;
      for(int j=0; j<n; j++)
      {if(a[j]!=b[j]) tr=1;}
      
      if(tr==0)
      {
          cout<<"YES";
          return 0;
      }
      
      for(int j=0; j<n; j++)
      {
          a[j]=a[j]+1;
          if(a[j]>=l)
            a[j]=0;
           
      }
      
  }
  
  for(int i=0; i<n-1; i++)
    {a[i+1]=a[i]+a[i+1];
     a[i]=a[i+1]-a[i];
     a[i+1]=a[i+1]-a[i]; }
  
  }
  cout<<"NO";
  
}