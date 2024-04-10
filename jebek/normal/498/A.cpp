#include <iostream>
#include<algorithm>

using namespace std;

long long a,b,c,x[2],y[2],n,ans;

int f(int i)
{
    if(b==0)
    {
        //cout<<i<<" "<<x[i]*a<<" "<<c<<endl;
        if(x[i]*a<-c)
            return 0;
        else
            return 1;
    }
   // cout<<i<<" "<<a*x[i]+c<<" "<<(-b)*y[i]<<endl;
    if(a*x[i]+c<(-b)*y[i])
        return 1;
    else
        return 0;
}

int main()
{
    cin>>x[0]>>y[0]>>x[1]>>y[1]>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>c;
       // cout<<f(0)<<" "<<f(1)<<endl;
        if(f(0)!=f(1))
            ans++;
    }
    cout<<ans<<endl;
}