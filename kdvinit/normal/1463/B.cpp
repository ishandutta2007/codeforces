#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;

    for(int q=0; q<t; q++)
    {
        int n;
        cin>>n;

        int a[n],s=0;

        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            s+=a[i];
        }
        if(1==1)
        {
            int s1=0,s2=0;
            if(n%2==0)
            {
               for(int i=0;i<n/2;i++)
               {
                   s1+=a[2*i];
                   s2+=a[2*i+1];
               }
               if(s1>s2)
               {
                    for(int i=0;i<n/2;i++)
                    {
                        a[2*i+1]=1;
                    }
               }
               else
               {
                   for(int i=0;i<n/2;i++)
                    {
                        a[2*i]=1;
                    }
               }

            }
            else
            {
                for(int i=0;i<n/2;i++)
               {
                   s1+=a[2*i];
                   s2+=a[2*i+1];
               }
               s1+=a[n-1];
               if(s1>s2)
               {
                    for(int i=0;i<n/2;i++)
                    {
                        a[2*i+1]=1;
                    }
               }
               else
               {
                   for(int i=0;i<n/2;i++)
                    {
                        a[2*i]=1;
                    }
                    a[n-1]=1;
               }
            }
            for(int i=0;i<n;i++)
        {
            cout<<a[i]<<endl;
        }
        }
        
    }
}