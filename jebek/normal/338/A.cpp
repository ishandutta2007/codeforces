#include <iostream>

using namespace std;

long long n,m,k,x,a,t,ans;
const long long MOD=1000000009;

long long po(long long q,long long w)
{
    long long c=1;
    while(w>0)
    {
       // cout<<w<<" "<<q<<endl;
        if(w%2==1)
            c*=q;
        c=c%MOD;
        q*=q;
        q=q%MOD;
        w=w/2;
      //  cout<<c<<endl;
    }
    return c;
}

int main()
{
 //   cout<<"*";
    cin>>n>>m>>k;
    m=n-m;
    if(n-m<=(m+1)*(k-1))
    {
        cout<<n-m<<endl;
        return 0;
    }
    x=n-m*k;
    ans=x%k+m*(k-1);
    a=x/k;
    long long p=po(2,a+1)-2;
    if(p<0)
        p+=MOD;
  //  cout<<x<<" "<<a<<" "<<k<<" "<<p<<endl;
    ans+=(k*p)%MOD;
    cout<<ans%MOD<<endl;
}