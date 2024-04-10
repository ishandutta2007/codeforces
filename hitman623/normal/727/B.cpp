#include <iostream>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{  cout<<fixed<<setprecision(2);
   double c=0,b=0;
   int i,m,d=0;
   char a[1001];
   cin>>a;
   m=strlen(a);
   for(i=0;i<m;++i)
   {  b=0;d=0;
       if(!isalpha(a[i]))
       { while(isdigit(a[i]))
         { b=b*10+a[i]-48;
         ++i; }
         if(a[i]=='.')
         {
             if(isdigit(a[i+3]))
                { ++i;
                    while(isdigit(a[i]))
                   { b=b*10+a[i]-48;
                      ++i; }
                 if(a[i]=='.')
                {
                 if(isdigit(a[i+3]))
                   { ++i;
                   while(isdigit(a[i]))
                   { b=b*10+a[i]-48;
                      ++i; }
                      if(a[i]=='.')
                        {b=b*10 +(a[i+1]-48);
                        b=b*10 + (a[i+2]-48);i+=2;d+=2; }
                   }
                  else {b=b*10 +(a[i+1]-48);
                        b=b*10 +(a[i+2]-48);i+=2;d+=2; }
                }
                }
             else {b=b*10 +(a[i+1]-48);
                        b=b*10 + (a[i+2]-48);i+=2;d+=2; }
       }
              b/=pow(10,d);
        c+=b;
       }
   }
   int f=0;
   if((int)(c/1000000)){ cout<<(int)c/1000000<<'.';f=1;}
   c=c-((int)(c/1000000))*1000000;
   int bb=(int)c/1000;
   if(!(bb/100) && f==1) cout<<'0';
   if(!(bb/10) && f==1) cout<<'0';
   if(bb || f==1) {cout<<bb<<'.';f=1;}
   c=c-((int)(c/1000))*1000;
   bb=(int)c;
   if(!(bb/100) && f==1) cout<<'0';
   if(!(bb/10) && f==1) cout<<'0';
   if(c-(int)c==0) cout<<setprecision(0)<<c;
   else cout<<c;
    return 0;
}