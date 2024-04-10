#include<bits/stdc++.h>
using namespace std;
map<int,int> cnt;
int x[200100];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cnt.clear();
        int n;
        cin>>n;
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>x[i];
            x[i]-=i;
            ans+=cnt[x[i]];
            cnt[x[i]]++;
        }
        cout<<ans<<endl;
    }
    return 0;
}