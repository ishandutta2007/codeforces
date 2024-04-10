#include <bits/stdc++.h>

using namespace std;
long n,a,b,x[500000],y[500000],i,xx[8];
char c[500001],rdu='W',rdd='W',ldu='W',ldd='W',rr='W',rl='W',cu='W',cd='W';
int main()
{
    cin>>n>>a>>b;
    for(i=0;i<n;++i)
    {
        cin>>c[i]>>x[i]>>y[i];
    }
    xx[0]=xx[2]=xx[4]=xx[6]=1000000007;
    xx[1]=xx[3]=xx[5]=xx[7]=-1000000007;
    for(i=0;i<n;++i)
    {
        if(y[i]-x[i]==b-a)
        {
            if(x[i]>a)
            {
              if(xx[0]>x[i]) {rdu=c[i];xx[0]=x[i];}
            }
            else
            {
              if(xx[1]<x[i]) {rdd=c[i];xx[1]=x[i];}
            }
        }

         if(y[i]+x[i]==b+a)
        {
             if(y[i]>b)
            {
              if(xx[2]>y[i]) {ldu=c[i];xx[2]=y[i];}
            }
             else
            {
              if(xx[3]<y[i]) {ldd=c[i];xx[3]=y[i];}
            }
        }

        if(y[i]==b)
        {
            if(x[i]>a)
            {
                if(x[i]<xx[4]) {rr=c[i];xx[4]=x[i];}
            }
            else
            {
                if(x[i]>xx[5]) {rl=c[i];xx[5]=x[i];}
            }
        }

        if(x[i]==a)
        {
            if(y[i]>b)
            {
                if(y[i]<xx[6]) {cu=c[i];xx[6]=y[i];}
            }
            else
            {
                if(y[i]>xx[7]) {cd=c[i];xx[7]=y[i];}
            }
        }
    }
    if(rdu=='B' || rdu=='Q' || rdd=='B' || rdd=='Q' || ldu=='B' || ldu=='Q' || ldd=='B' || ldd=='Q' ||
       cu=='R' || cu=='Q' || cd=='R' || cd=='Q' || rr=='R' || rr=='Q' || rl=='R' || rl=='Q' )
        cout<<"YES";
    else cout<<"NO";
    return 0;
}