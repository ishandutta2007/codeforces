#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int n;
int ds[10009],d[10009];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>n>>k;

        cin>>s;
        d[n]=ds[-1]=1000000002;
        for(int i=0;i<n;i++)
        {
            ds[i]=ds[i-1]+1;
            if(s[i]=='1')ds[i]=0;
        }
       for(int i=n-1;i>=0;i--)
        {
            d[i]=d[i+1]+1;
            if(s[i]=='1')d[i]=0;
        }
        for(int i=0;i<n;i++)
         {if(s[i]=='1'){cout<<1;continue;}

         if(ds[i]==d[i]){cout<<0;continue;}
         if(k<min(ds[i],d[i]))cout<<0;
         else cout<<1;
         }
        cout<<endl;

    }

    return 0;
}