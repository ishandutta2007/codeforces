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
           cin>>n>>k;
           multiset<ll>pos,neg;
           for(int i=0;i<n;i++)
           {
               cin>>a[i];
               if(a[i]>0)pos.insert(a[i]);
               else if(a[i]<0) neg.insert(abs(a[i]));

           }
           auto it=pos.begin();
           int ps=0,ng=0;

           if(!pos.empty())ps=*(--pos.end());
           if(!neg.empty())ng=*(--neg.end());
           mx=max(ps,ng);
           ans=0;
          for(;it!=pos.end();)
          {
              int tmp=k;
              ll si=pos.size();
              if(si<=k)
              {
                  auto it2=--pos.end();
                  ll tmp=*it2;
                  ans+=2*tmp;
                  break;
              }
              else
              {
                  if(si%k!=0)
                  {
                      int tmp=si%k;
                      while(tmp!=0)
                      {
                         if(tmp==1)
                         {ll ad=*pos.begin();ans+=2*ad;}
                          it++;pos.erase(pos.begin());
                          if(it==pos.end())break;
                         tmp--;

                      }
                  }
                  else
                  {
                      int tmp=k;
                      while(tmp!=0)
                      {
                         if(tmp==1)
                         {ll ad=*pos.begin();ans+=2*ad;}
                          it++;pos.erase(pos.begin());
                          if(it==pos.end())break;
                         tmp--;

                      }
                  }
              }
          }
          it=neg.begin();

          for(;it!=neg.end();)
          {
              int tmp=k;
              ll si=neg.size();
              if(si<=k)
              {
                  auto it2=--neg.end();
                  ll tmp=*it2;
                  ans+=2*tmp;
                  break;
              }
              else
              {
                  if(si%k!=0)
                  {
                      int tmp=si%k;
                      while(tmp!=0)
                      {
                         if(tmp==1)
                         {ll ad=*neg.begin();ans+=2*ad;}
                          it++;neg.erase(neg.begin());
                          if(it==neg.end())break;
                         tmp--;

                      }
                  }
                  else
                  {
                      int tmp=k;
                      while(tmp!=0)
                      {
                         if(tmp==1)
                         {ll ad=*neg.begin();ans+=2*ad;}
                          it++;neg.erase(neg.begin());
                          if(it==neg.end())break;
                         tmp--;

                      }
                  }
              }
          }


        cout<<ans-mx<<endl;
        }




    return 0;
}