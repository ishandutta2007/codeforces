#include <iostream>
#include<algorithm>

using namespace std;

long long x,a,b,c,r[200],t[200],MAX,k,k1,m,sum,n;

bool check()
{
    if(r[0]<t[0] || (r[0]-t[0])%(b-a)!=0)
        return false;
    int k=(r[0]-t[0])/(b-a);
    r[1]-=k;
    t[1]-=k;
    for(int i=1;i<70;i++)
    {
       // cout<<i<<" "<<r[0]<<" "<<t[0]<<" "<<r[1]<<" "<<t[1]<<endl;
        if(r[i]<t[i] || (r[i]-t[i])%(b-a)!=0)
            return false;
        k=(r[i]-t[i])%(b-a);
        r[i]-=k*b;
        t[i]-=k*a;
        k=__gcd(a,b);
        k1=b/k;
        MAX=0;
        if(r[i]<0)
            MAX=((-r[i]+a-1)/a+k1-1)/k1;
        if(t[i]<0)
            MAX=max(MAX,((-t[i]+a-1)/a+k1-1)/k1);
        r[i+1]-=MAX*(b/k);
        t[i+1]-=MAX*(a/k);
    }
    if(r[70]<0 || t[70]<0)
        return false;
    return true;
}

int main()
{
    cin>>a>>b>>c;
    if(a!=b)
    {
        if(b<a || c<b)
        {
            if(b==c)
                cout<<1<<endl;
            else
                cout<<0<<endl;
            return 0;
        }
        x=c;
        while(x>0)
        {
            t[m++]=x%b;
            sum+=x%b;
            x/=b;
        }
        if(a==1)
        {
            if(sum>b || sum%(b-1)!=b%(b-1))
                cout<<0<<endl;
            else
                cout<<1<<endl;
            return 0;
        }
        x=b;
        while(x)
        {
            r[n++]=x%a;
            x/=a;
        }
        if(check())
            cout<<1<<endl;
        else
            cout<<0<<endl;
   }
    else
    {
        if(c!=b)
        {
            cout<<0<<endl;
            return 0;
        }
        if(a==1)
            cout<<"inf"<<endl;
        else
            cout<<2<<endl;
    }
}