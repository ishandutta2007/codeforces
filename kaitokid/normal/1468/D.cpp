#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
   ios::sync_with_stdio(0);
   cin.tie(0);
   int t,n,m,a,b;
   cin>>t;
   while(t--)
   {


   cin>>n>>m>>a>>b;
   multiset<int>st;
   int x;
   for(int i=0;i<m;i++)
       {cin>>x;
       st.insert(x);}
       int nm=abs(a-b)-1,r;
       if(a<b)r=a;
       else r=n-a+1;
       r+=nm-1;
       int ans=0;
       for(int i=r;i>r-nm;i--)
       {
           multiset<int>::iterator it=st.upper_bound(i);
           if(it==st.begin())break;
           ans++;
           it--;
           st.erase(it);
       }
       cout<<ans<<endl;
   }
    return 0;
}