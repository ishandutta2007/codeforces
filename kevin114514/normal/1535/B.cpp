#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(!b)
        return a;
    return gcd(b,a%b);
}
int a[2020];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        vector<int> v;
        for(int i=0;i<n;i++)
            if(a[i]%2==0)
                v.push_back(a[i]);
        for(int i=0;i<n;i++)
            if(a[i]%2==1)
                v.push_back(a[i]);
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(gcd(v[i],v[j]*2)>1)
                    ans++;
        cout<<ans<<endl;
    }
    return 0;
}