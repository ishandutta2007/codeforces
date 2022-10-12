
#include <iostream>
#include <string>

using namespace std;

int main()
{
     int n, w=0;
     cin>>n;
     string s;
     int a;
     int f=0;
     for(int i=0; i<n; i++)
     {
         cin>>a>>s;
         
        {
        if((w==0)&&(s!="South"))
          f=1;
        if((w==20000)&&(s!="North"))
          f=1;
        }
         if(s=="North")
            w=w-a;
          if(s=="South")
            w=w+a;
        if(w<0)
          f=1;
        if(w>20000)
          f=1;
       
     }
     if(w!=0)
       f=1;
       
     if(f==1)
       cout<<"NO";
      else
      cout<<"YES";
   
}