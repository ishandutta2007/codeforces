#include <bits/stdc++.h>

using namespace std;
set<int> a,b;
map<int,int>v;
int main()
{int n;
cin>>n;
int x;
for(int i=0;i<n;i++)

    {
        cin>>x;
        v[x]=i+1;
        a.insert(x);
    }
  string s;
  cin>>s;
  for(int i=0;i<2*n;i++)
  {
      if(s[i]=='0'){cout<<v[(*a.begin())]<<" ";b.insert(*a.begin());a.erase(*a.begin());}
     if(s[i]=='1'){set<int> ::iterator it=b.end(); it--;cout<<v[(*it)]<<" ";b.erase(*it);}
  }
    return 0;
}