#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<int,bool>mp;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,k;
        mp.clear();
        cin>>n>>k;
        bool ans=false;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            if(mp[x+k]||mp[x-k])ans=true;
            mp[x]=true;
        }
        if(ans)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

    }
    return 0;
}