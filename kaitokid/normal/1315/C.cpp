#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int t,n,b[400],a[400];
set<int>x,y;

int main()
{
    ios::sync_with_stdio(0);
    cin>>t;
   while(t--)
   {bool bl=false;
       y.clear();
       cin>>n;
       for(int i=1;i<=2*n;i++)y.insert(i);
       for(int i=1;i<=n;i++){cin>>b[i];y.erase(b[i]);}
       for(int i=1;i<=2*n;i++)
       {
           if(i%2){a[i]=b[(i+1)/2];continue;}
           set<int>::iterator it=y.upper_bound(b[i/2]);
           if(it==y.end()){bl=true;break;}
           a[i]=(*it);
           y.erase(it);
       }
       if(bl){cout<<-1<<endl;continue;}
       for(int i=1;i<=2*n;i++)cout<<a[i]<<" ";
       cout<<endl;
              }
    return 0;
}