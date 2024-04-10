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
           cin>>n>>a[0];
           ans=1;
           if(a[0])
           ans=2;
           for(int i=1;i<n;i++)
           {
               cin>>a[i];
               if(a[i]&&ans!=-1)
               {
                   if(a[i-1])ans+=5;
                   else ans++;
               }
               else if(!a[i])
               {
                   if(!a[i-1])ans=-1;
               }

           }
           cout<<ans<<endl;


        }




    return 0;
}