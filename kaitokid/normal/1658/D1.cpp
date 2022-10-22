#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int sum[21];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int l,r,x;
        cin>>l>>r;
        for(int i=0;i<20;i++)sum[i]=0;
        for(int i=l;i<=r;i++)
        {
            cin>>x;
            for(int j=0;j<18;j++){if(x&(1<<j))sum[j]++;
            if(i&(1<<j))sum[j]--;
            }
        }
       int ans=0;
       for(int i=0;i<18;i++)if(sum[i]!=0)ans|=(1<<i);
       cout<<ans<<endl;

    }
    return 0;
}