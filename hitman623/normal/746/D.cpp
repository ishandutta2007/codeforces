#include <bits/stdc++.h>

using namespace std;

int main()
{
   long long n,k,a,b,i,f=0;
   cin>>n>>k>>a>>b;
   char aa[100000],bb[100000];
   for(i=0;i<k;++i)
    {aa[i]='G';
      bb[i]='B';}
      aa[i]='\0';
      bb[i]='\0';
      if(a>b) f=1;
      if((b+1)*k<a || (a+1)*k<b) {cout<<"NO";exit(0);}
   while(n>0)
   {
       if(a>b)
       {
           if(f==1)
           {if(a>=k) {cout<<aa;a-=k;n-=k;}
           else {for(i=0;i<a;++i)
                 cout<<'G';n-=i;a=0;}
                 f=0;
           }
           else
            {
                if(b>0){cout<<'B';b--;n--;}
                else {}
                f=1;
            }
       }
       else
       {   if(f==0)
           {if(b>=k) {cout<<bb;b-=k;n-=k;}
           else {for(i=0;i<b;++i)
                 cout<<'B';n-=i;b=0;}
                 f=1;
           }
           else
           {
               if(a>0) {cout<<'G';a--;n--;}
               else {}
               f=0;
           }
       }
   }
    return 0;
}