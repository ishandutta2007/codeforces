#include <iostream>
#include<algorithm>

using namespace std;

long long n,v,a,b,k,x,ans;
long long t[4000];

int main()
{
    cin>>n>>v;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        t[a]+=b;
    }
    for(int i=1;i<=3010;i++)
    {
        k=v;
        x=min(k,t[i-1]);
        t[i-1]-=x;
        k-=x;
        x=min(k,t[i]);
        t[i]-=x;
        k-=x;
        ans+=v-k;
    }
    cout<<ans<<endl;
}