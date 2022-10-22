#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        int ans=0;
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        int x=a[n-1];
        for(int i=n-1;i>=0;i--)
        {
            if(a[i]>x){ans++;x=a[i];}
        }
        cout<<ans<<endl;
    }
    return 0;
}