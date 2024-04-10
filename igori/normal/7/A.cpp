
#include <iostream>
#include <string>

using namespace std;

int main()
{
    char a[8][8];
    string n;
    int hh=0;
    int k=0;
    
    for(int i=0; i<8; i++)
    {
        cin>>n;
        for(int j=0; j<8; j++)
        {
            a[i][j]=n[j];
        }
        
    }
    for(int i=0; i<8; i++)
    {
        hh=0;
        for(int j=0; j<8; j++)
           {
               if(a[i][j]=='B')
               {
                   hh++;
               }
           }
        if(hh==8)
          k++;
            
    }
    for(int i=0; i<8; i++)
    {
        hh=0;
        for(int j=0; j<8; j++)
           {
               if(a[j][i]=='B')
               {
                   hh++;
               }
           }
        if(hh==8)
          k++;
            
    }
    if(k!=16)
      cout<<k;
     else 
     cout<<8;
}