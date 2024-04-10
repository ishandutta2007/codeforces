#include <iostream>
using namespace std;
int main()
{ int n;
  cin>>n;
  char a[1000][5];
  int t=0;
  for(int i=0;i<n;i++)
  { 
    for(int j=0;j<5;j++)
    {
        cin>>a[i][j];
       
        if((a[i][j]==a[i][j-1])&&(a[i][j]=='O')&&(t==0)&&(j>0)&&(j!=3))
        {
            a[i][j]='+';
            a[i][j-1]='+';
            t=1;
        }
        
        
    }
  }

  if(t==0)
  {
     cout<<"NO";
  }

  if(t==1)
  { cout<<"YES"<<endl;
      for(int i=0;i<n;i++)
  { 
    for(int j=0;j<5;j++)
    {
       cout<<a[i][j];
        
    }
    cout<<endl;
    
  }   
  }
  
      
    
    
    
}