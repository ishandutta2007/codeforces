#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200009],b[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        bool ans=true;
        b[n]=b[0];
        for(int i=0;i<n;i++)
        {if(b[i]<a[i])ans=false;
        if(b[i]>max(a[i],b[i+1]+1))ans=false;}
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}