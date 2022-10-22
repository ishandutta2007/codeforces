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
        int n,k;
        cin>>n>>k;
        for(int i=0;i<n;i++)
            cin>>a[i];

        if(k>=n){cout<<0<<endl;continue;}
        sort(a,a+n);
        int mex=0;
        int df=1;
        int ff=n,h=0;

        for(int i=0;i<n;i++)
        {
            if(a[i]==mex){mex++;continue;}
            if(a[i]<mex)continue;
            if(k==0)break;
            df++;
            mex++;
            h++;
            i--;
            k--;
            n--;
        }

        if(a[ff-1]<mex){cout<<0<<endl;continue;}
        int cur=1;
        vector<int>rr;
        for(int i=ff-2;i>=0;i--)
        {
            if(a[i]<mex)break;
            if(a[i]<a[i+1]){rr.push_back(cur);cur=1;continue;}
            cur++;
        }
        rr.push_back(cur);
        int ans=rr.size();
        sort(rr.begin(),rr.end());
        for(int i=0;i<rr.size();i++)
        {
            if(rr[i]<=h){ans--;h-=rr[i];}
        }
        cout<<ans<<endl;

    }
    return 0;

}