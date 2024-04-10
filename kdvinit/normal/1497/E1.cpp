/*
Not My Submission
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
int seive[10000005];
int32_t main()
{ios::sync_with_stdio(0);
 cin.tie(0);
 memset(seive,-1,sizeof(seive));
 seive[0]=0;seive[1]=0;
 for(int i=2;i<10000005;i++)
    {if(seive[i]==-1)
        {seive[i]=i;
         for(int j=i*i;j<10000005;j+=i)
            {seive[j]=i;
            }
        }
    }
int t;
cin>>t;
while(t--)
    {int n,k;cin>>n>>k;
     int a[n];
     for(int i=0;i<n;i++)
        {cin>>a[i];
        }
        int ans=0;
     set<vector<int>> m;
     for(int i=0;i<n;i++)
        {map<int,int> z;
         int ok=a[i];
         while(ok>1)
            {z[seive[ok]]++;
             ok=ok/seive[ok];
            }
        vector<int> v;
        for(auto x:z)
            {if(x.second%2){v.push_back(x.first);}
            }
        if(m.find(v)!=m.end())
            {ans++;m.clear();
            }
        m.insert(v);
        }
    cout<<ans+1<<"\n";
    }
}