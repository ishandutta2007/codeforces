#include<bits/stdc++.h>
using namespace std;
long long nega[100100],np,posi[100100],pp;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        np=pp=0;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            long long x;
            cin>>x;
            if(x<0)
                nega[np++]=x;
            else    posi[pp++]=x;
        }
        sort(nega,nega+np);
        sort(posi,posi+pp);
        reverse(posi,posi+pp);
        long long ans=-1e18-1e18-1e18;
        for(int i=0;i<=np&&i<=5;i+=2)
        if(5-i<=pp)
        {
            long long tmp=1;
            for(int j=0;j<i;j++)
                tmp*=nega[j];
            for(int j=0;j<5-i;j++)
                tmp*=posi[j];
            ans=max(ans,tmp);
        }
        reverse(nega,nega+np);
        reverse(posi,posi+pp);
        for(int i=1;i<=np&&i<=5;i+=2)
        if(5-i<=pp)
        {
            long long tmp=1;
            for(int j=0;j<i;j++)
                tmp*=nega[j];
            for(int j=0;j<5-i;j++)
                tmp*=posi[j];
            ans=max(ans,tmp);
        }
        cout<<ans<<endl;
    }
}