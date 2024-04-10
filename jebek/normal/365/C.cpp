#include <iostream>
#include<algorithm>
#include<string>

using namespace std;

long long k,a[50000],sum1[50000],b[10000000],n,ans=0,MAX;
string s;

int main()
{
    cin>>k;
    cin>>s;
    n=s.size();
    for(int i=0;i<s.size();i++)
        a[i]=int(s[i]-'0');
    sum1[0]=a[0];
    for(int i=1;i<n;i++)
    {
        sum1[i]=sum1[i-1]+a[i];
        MAX=max(MAX,sum1[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(sum1[i]>=0)
            b[sum1[i]]++;
        for(int j=0;j<i;j++)
            if(sum1[i]-sum1[j]>=0)
                b[sum1[i]-sum1[j]]++;
    }
    if(k==0)
    {
        for(int i=1;i<=MAX;i++)
            ans+=b[i]*b[0];
        ans=ans*2;
        ans+=b[0]*b[0];
        cout<<ans<<endl;
        return 0;
    }
    for(int i=1;i<=MAX;i++)
        if(k%i==0 && k/i<10000000)
            ans+=b[i]*b[k/i];
    cout<<ans<<endl;
}