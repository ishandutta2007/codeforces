#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[109];
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
        for(int i=0;i<n;i++)
        {
            int x;
            char c;
            cin>>x;
            while(x--){cin>>c;if(c=='D')a[i]=(a[i]+1)%10;else a[i]=(a[i]+9)%10;}
        }
        for(int i=0;i<n;i++)cout<<a[i]<<" ";
        cout<<endl;

    }
    return 0;

}