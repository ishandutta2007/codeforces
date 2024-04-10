#include<bits/stdc++.h>
#define int long long
using namespace std;
int32_t main()
{ios::sync_with_stdio(0);
 cin.tie(0);
 int q;
 set<pair<int,int>> s;
 set<int> lol;
 map<int,int> m;
 int curr=1;
 int qtype;
 cin>>q;
 while(q--)
    {cin>>qtype;
     if(qtype==1)
        {int z;cin>>z;
         m[curr]=z;
         s.insert(make_pair(-z,curr));
         lol.insert(curr);
         curr++;
        }
    if(qtype==2)
        {cout<<*(lol.begin())<<" ";int z=*(lol.begin());lol.erase(lol.begin());
         s.erase(s.find(make_pair(-m[z],z)));
        }
    if(qtype==3)
        {auto ok=*(s.begin());
         cout<<ok.second<<" ";
         s.erase(s.begin());
         lol.erase(lol.find(ok.second));
        }
    }
}