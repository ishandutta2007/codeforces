#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    int t,n,x;
    cin>>t;
    while(t--)
    {
        int d;
        cin>>n>>x;
        int a[2]={0,0};
        for(int i=0;i<n;i++)
        {
            cin>>d;
            a[d%2]++;
        }
       if(a[1]==0){cout<<"No\n";continue;}
       a[1]=min(a[1],x);
       if(a[1]%2==0)a[1]--;

        if(a[1]+a[0]<x){cout<<"No\n";continue;}
        cout<<"Yes\n";
    }
    return 0;
}