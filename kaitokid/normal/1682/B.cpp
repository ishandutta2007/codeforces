#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

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
        int ans=(1<<22)-1;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            if(i!=x){ans&=i;ans&=x;}
        }
        cout<<ans<<endl;
    }
    return 0;
}