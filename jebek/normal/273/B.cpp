#include <iostream>
#include<algorithm>
#include<set>
#include<map>

using namespace std;

long long n,ans,a[100100],b,k,MOD,f[200100],x,ans2,ans3,c[200100],f1,f2;
set<long long>s;
map<long long,long long>m,m1;


int main()
{
    cin>>n;
    ans=1;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s.insert(a[i]);
        m[a[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        cin>>b;
        if(b==a[i])
            m1[b]++;
        s.insert(b);
        m[b]++;
    }
    cin>>MOD;
    f[0]=1;
    for(long long i=1;i<=200010;i++)
        f[i]=(f[i-1]*i)%MOD;
    for(long long i=2;i<=200010;i++)
        c[i]=(i*(i-1)/2)%MOD;
    while(s.size())
    {
        x=*s.begin();
        s.erase(s.begin());
        f1=m[x];f2=m1[x];
        while(f2>0)
        {
            ans=(ans*c[f1])%MOD;
            f2--;
            f1-=2;
        }
        ans=(ans*f[f1])%MOD;
    }
    cout<<ans<<endl;
}