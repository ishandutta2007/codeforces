#include <iostream>

using namespace std;

int main()
{
    char a[20],b,i;long long ans=0;
    int m=0;
    long long c=0;
    cin>>a;
    for(i=0;a[i]!=0;++i)
        m++;
      b=a[i-1];
      for(i=0;i<m-1;++i)
       c=c*10+a[i]-48;
     ans=((c-1)/4)*16;
     if(!(c&1)) ans+=7;
      switch(b)
      {
         case 'a':ans+=4;break;
         case 'b':ans+=5;break;
         case 'c':ans+=6;break;
         case 'd':ans+=3;break;
         case 'e':ans+=2;break;
         case 'f':ans+=1;break;
      }
      cout<<ans;
   return 0;
}