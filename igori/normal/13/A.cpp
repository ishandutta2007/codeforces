
#include <iostream>
#include <string>
#include <algorithm>



using namespace std;

int main()
{
     int a=0;
     int b=0;
     int n;
     cin>>n;
     b=n-2;
     
     int chisla[10]={0};
     int k=1;
     int l=n;
     for(int i=2; i<n; i++)
     {
         k=1;
         l=n;
         chisla[9]=l%i;
         l=l/i;
         chisla[8]=l%i;
         l=l/i;
         chisla[7]=l%i;
         l=l/i;
         chisla[6]=l%i;
         l=l/i;
         chisla[5]=l%i;
         l=l/i;
         chisla[4]=l%i;
         l=l/i;
         chisla[3]=l%i;
         l=l/i;
         chisla[2]=l%i;
         l=l/i;
         chisla[1]=l%i;
         l=l/i;
         chisla[0]=l%i;
         l=l/i;
         a=a+chisla[0]+chisla[1]+chisla[2]+chisla[3]+chisla[4]+chisla[5]+chisla[6]+chisla[7]+chisla[8]+chisla[9];
         for(int j=0; j<10; j++)
         {
             chisla[j]=0;
         }
     }
     
     for(int i=b; i>1; i--)
     {
         if((a%i==0)&&(b%i==0))
         {
             a=a/i;
             b=b/i;
             break;
         }
     }
     
     cout<<a<<"/"<<b;
     
}