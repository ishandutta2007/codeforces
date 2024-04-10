#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    cin>>t;
    while(t--)
    {
        int sum=0;
        bool bl=false;
        cin>>n;
        int x;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            sum+=x;
            if(x==1)bl=true;
        }
        if(sum%2){cout<<"NO\n";continue;}
        sum/=2;
        if(bl||(sum%2==0))cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}