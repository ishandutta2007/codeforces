#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using pi =pair<int,int>;

#define f first

#define s second

# define be(v) (v).begin(),(v).end()

#define eb(v)  (v).begin(),(v).end(),greater<int>()




ll t,m,n,x,y,z,k,mn=1e9,mx,ans,cnt,a[500003],b[500003],sum;



string s;

bool yes;


int main()
{

 ios_base::sync_with_stdio(false);





        cin>>t;
        while(t--)
        {
            cin>>x>>y;
            ans=0;

            ll x1,x2,y1,y2,xx1,xx2,yy1,yy2;
            cin>>n>>x1;

            for(int i=1;i<n-1;i++)cin>>x2;cin>>x2;

            ans=max(ans,(x2-x1)*y);
            cin>>n>>xx1;


            for(int i=1;i<n-1;i++)cin>>xx2;cin>>xx2;
            ans=max(ans,(xx2-xx1)*y);
            cin>>n>>y1;

            for(int i=1;i<n-1;i++)cin>>y2;cin>>y2;
            ans=max(ans,(y2-y1)*x);
            cin>>n>>y1;

            for(int i=1;i<n-1;i++)cin>>y2;cin>>y2;
            ans=max(ans,(y2-y1)*x);
            cout<<ans<<endl;









        }




    return 0;
}