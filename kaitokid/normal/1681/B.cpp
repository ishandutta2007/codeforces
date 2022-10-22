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
        int n,m,s=0;
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        cin>>m;
        for(int i=0;i<m;i++)
        {cin>>b[i];s+=b[i];s%=n;}

        s%=n;
        cout<<a[s]<<endl;
    }
    return 0;
}