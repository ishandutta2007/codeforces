#include<bits/stdc++.h>
using namespace std;
int a[200009];
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
        bool ans=true;
        for(int i=2;i<n;i++)
        {
            if((a[i]%2)!=(a[i-2]%2))ans=false;
        }
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;

}