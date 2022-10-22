#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans[200009];
ll fr[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        for(int i=0;i<=n;i++)fr[i]=0;
        for(int i=0;i<n;i++){int x;cin>>x;fr[x]++;}
        ans[0]=fr[0];
        vector<ll>v;
        int d=n+1;
        ll res=0;
        for(int i=1;i<=n;i++)
        {
        if(fr[i-1]==0)
        {
            if(v.empty()){d=i;break;}
            res+=i-1-v.back();
            v.pop_back();
        }
        ans[i]=res+fr[i];
        for(int j=1;j<fr[i-1];j++)v.push_back(i-1);

        }
        for(int i=0;i<d;i++)cout<<ans[i]<<" ";
        for(int i=d;i<=n;i++)cout<<-1<<" ";
        cout<<endl;

    }

    return 0;
}