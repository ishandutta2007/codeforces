#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod=998244353;
int n;
int a[509],b[509];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>b[i];
        bool ans=true;
        vector<pair<int,int> >v;
        if(a[1]!=b[1]){cout<<"NO"<<endl;continue;}
        for(int i=2;i<=n;i++)
        {
            if(a[i]==b[i])continue;
            bool d=false;
            for(int j=i;j<n;j++)
                if(a[j]==b[i] && a[j+1]==b[i-1])
            {
                v.push_back({i-1,j+1});
                reverse(a+i-1,a+j+2);
                d=true;
                break;
            }
            if(d)continue;
            for(int j=i+1;j<=n;j++)
            {

                if(a[j]==b[i] && a[j-1]==b[i-1])
                for(int u=i;u<=j-1;u++)
                for(int q=j;q<=n;q++)
                {
                    if(d)break;
                    if(a[u]==a[q])
                    {
                        v.push_back({u,q});
                        reverse(a+u,a+q+1);
                        d=true;
                    }

                }
               bool d2=false;
                for(int q=i;q<n;q++)
                if(a[q]==b[i] && a[q+1]==b[i-1])
            {
                if(d2)break;
                v.push_back({i-1,q+1});
                reverse(a+i-1,a+q+2);
                d2=true;
                break;
            }

            if(d)break;
            }

          if(!d){ans=false;break;}
        }
        if(!ans){cout<<"NO"<<endl;continue;}
        cout<<"YES"<<endl;
        cout<<v.size()<<endl;
        for(int i=0;i<v.size();i++)cout<<v[i].first<<" "<<v[i].second<<endl;

        }
    return 0;
}