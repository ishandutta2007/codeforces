#include<bits/stdc++.h>
#define int long long
using namespace std;
int fact[23];
int solve(vector<int> l)
{sort(l.begin(),l.end());
 map<int,int> arr;
 for(auto x:l)
    {arr[x]++;
    }
 int pro=1;
 for(int i=2;i<2+l.size();i++)
   {
       pro=pro*(lower_bound(l.begin(),l.end(),i)-l.begin()-(i-2));
   }
for(auto x:arr)
    {pro=pro/fact[x.second];
    }
return pro;
}
vector<int> lol(int z)
{int curr=2;vector<int> v;
while(z>0)
    {v.push_back(z%curr);
     z=z/curr;
     curr++;
    }
return v;
}
int32_t main()
{ios::sync_with_stdio(0);
 cin.tie(0);
 fact[0]=1;
 for(int i=1;i<23;i++){fact[i]=fact[i-1]*i;}
 int t;
 cin>>t;
 while(t--)
    {int n;cin>>n;
        vector<int> fi=lol(n);
        int ans=0;
        map<int,int> op;
        for(auto x:fi){op[x]=1;}
        for(auto i:op)
            {if(i.first==0){continue;}
             vector<int> l;
             int done=0;
             for(auto x:fi)
                {if(done==0 && x==i.first){done=1;continue;}
                 l.push_back(x);
                }
            ans+=solve(l);
            }
        cout<<ans-1<<"\n";
    }
}