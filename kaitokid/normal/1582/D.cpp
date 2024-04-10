#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[100009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        if((n%2)==0)
        {
            for(int i=0;i<n;i+=2)cout<<a[i+1]<<" "<<(-1*a[i])<<" ";
            cout<<endl;
            continue;
        }
        for(int i=0;i+3<n;i+=2)cout<<a[i+1]<<" "<<(-1*a[i])<<" ";
        if(a[n-2]+a[n-1]!=0)
        {cout<<a[n-2]+a[n-1]<<" "<<(-1*a[n-3])<<" "<<(-1*a[n-3])<<" ";
        cout<<endl;
        continue;}
        if(a[n-3]+a[n-2]!=0)
        {cout<<(-1*a[n-1])<<" "<<(-1*a[n-1])<<" "<<(a[n-3]+a[n-2])<<" ";
        cout<<endl;
        continue;}
        if(a[n-3]+a[n-1]!=0)
        {cout<<(-1*a[n-2])<<" "<<(a[n-1]+a[n-3])<<" "<<(-1*a[n-2])<<" ";
        cout<<endl;
        continue;}


    }
    return 0;
}