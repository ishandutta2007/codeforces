#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using pi =pair<int,int>;

#define f first

#define s second

# define be(v) (v).begin(),(v).end()

#define eb(v)  (v).begin(),(v).end(),greater<int>()




int t,m,n,x,y,z,k,mn=1e9,mx,ans,cnt,a[500003],b[500003],sum;



string s;

bool yes;



int main()
{

 ios_base::sync_with_stdio(false);





        cin>>t;
        while(t--)
        {
           cin>>n;
           for(int i=0;i<n;i++)
           {
               cin>>a[i];

           }
           ans=0;mx=a[n-1];
           for(int i=n-2;i>=0;i--)
           {
               if(mx<a[i])mx=a[i],ans++;
           }
           cout<<ans<<endl;


        }




    return 0;
}