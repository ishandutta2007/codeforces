#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int ans[400009];

pair<pair<int,int>,int> a[400009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int x,y;
        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
      a[i]={{x,y},i};
      a[i+n]={{y,x},i};
            ans[i]=-1;
        }

     sort(a,a+2*n);
     int u=1e9+1,r;
     int j=0;
     for(int i=0;i<2*n;i++)
     {
         while(j<i&&a[j].first.first<a[i].first.first)
            {
            if(a[j].first.second<u){u=a[j].first.second;r=a[j].second;}
            j++;
            }
         if(a[i].first.second>u){ans[a[i].second]=r+1;}
     }
   for(int i=0;i<n;i++)cout<<ans[i]<<" ";
   cout<<endl;
    }

    return 0;
}