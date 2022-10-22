#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<int>a[1009];
int c[1009],ans[1009];
bool bl[1009];
string s;
int main()
{
    ios::sync_with_stdio(0);
   int t,n,k;
   cin>>t;
   while(t--)
   {
       cin>>n>>k;
       int x;
       for(int i=0;i<k;i++)
       a[i].clear();
       for(int i=0;i<k;i++)
       {cin>>c[i];
       for(int j=0;j<c[i];j++){cin>>x;a[i].push_back(x);}}
       cout<<"? "<<n<<" ";
       for(int i=1;i<=n;i++){cout<<i<<" ";bl[i]=true;}
       cout<<endl;
       fflush(stdout);
       int mx;
       cin>>mx;
       int l=1,r=n;

       while(r>l)
       {
           int mid=(l+r)/2;
           cout<<"? "<<mid-l+1<<" ";
           for(int i=l;i<=mid;i++)cout<<i<<" ";
           cout<<endl;
           fflush(stdout);
           int u;
           cin>>u;
           if(u==mx)r=mid;else l=mid+1;
       }

       for(int i=0;i<k;i++)
       {
           ans[i]=mx;
           for(int j=0;j<c[i];j++){if(a[i][j]==l)
            {cout<<"? "<<n-c[i]<<" ";
    for(int q=0;q<c[i];q++)bl[a[i][q]]=false;
    for(int i=1;i<=n;i++)if(bl[i])cout<<i<<" ";
    cout<<endl;
    fflush(stdout);
    cin>>ans[i];

           }
       }
       }
       cout<<"! ";
       for(int i=0;i<k;i++)cout<<ans[i]<<" ";
       cout<<endl;
       fflush(stdout);
       cin>>s;
       if(s=="Incorrect")return 0;
       }    return 0;
}