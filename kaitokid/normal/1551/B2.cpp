#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200009],fr[200009],res[200009];
vector<int>pos[200009];
int n,k;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int ans=n;
        for(int i=1;i<=n;i++){fr[i]=0;pos[i].clear();}
        for(int i=0;i<n;i++)
        {
            res[i]=0;
            cin>>a[i];
            fr[a[i]]++;
            if(fr[a[i]]>k){fr[a[i]]=k;ans--;}
            else pos[a[i]].push_back(i);
        }
        ans-=(ans%k);
        int d=1;
        for(int i=1;i<=n;i++)
        {
            if(ans==0)break;
            for(int j=0;j<pos[i].size();j++)
            {
                if(ans==0)break;
                res[pos[i][j]]=d;
                d++;
                if(d==k+1)d=1;
                ans--;
            }

        }
        for(int i=0;i<n;i++)cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}