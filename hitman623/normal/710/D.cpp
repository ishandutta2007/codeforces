#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a1,a2,d1,d2,l,r,i,c=0,d=0;
    cin>>d1>>a1>>d2>>a2>>l>>r;
    if(d1==d2)
    {
        if((abs(a1-a2))%d1!=0) cout<<0;
        else {if(a1<a2) a1=a2; if(r>=a1)cout<<(r-a1)/d1+1;else cout<<0;}
        exit(0);
    }
    if(d1%2==0 && d2%2==0 && abs(a1+a2)%2==1) cout<<0,exit(0);
    if(d1>d2)
    {
       for(i=a1;i<=r;i+=d1)
       {
           if(i>=l && i>=a2)
           {
               if((i-a2)%d2==0) {c++;if(c==1)d=i;}
           }
           if(c==2) {d=(i-d)/d1;break;}
       }

       if(c==2 && d!=0)
       c+=((r-i)/d1)/d;
    }
    else if(d1<d2)
        {
       for(i=a2;i<=r;i+=d2)
       {
           if(i>=l && i>=a1)
           {
               if((i-a1)%d1==0) {c++;if(c==1)d=i;}
           }
           if(c==2) {d=(i-d)/d2;break;}
       }
       if(c!=0 && d!=0)
       c+=((r-i)/d2)/d;
    }
    cout<<c;
      return 0;
}