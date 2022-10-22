#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int v[100008];
multiset <int>a,b;
int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(v,v+n);
   for(int i=0;i<(n)/2;i++)
    a.insert(v[i]);
   for(int i=n/2;i<n;i++)
    b.insert(v[i]);
    vector<int> ans;
   multiset<int>::iterator it1,it2;
   it1=(b.end());
   it1--;
   int res=0;
   ans.push_back((*it1));
   b.erase(it1);
   while((!b.empty())&&(!a.empty()))
   {
       it1=b.end();
       it1--;
       int u=(*it1);
       it2= a.lower_bound(u);
       if(it2==a.begin())break;
       res++;
       it2--;
       ans.push_back((*it2));
       ans.push_back(u);
       a.erase(it2);
       b.erase(it1);

   }
   cout<<res<<endl;
   for(int i=0;i<ans.size();i++)
    cout<<ans[i]<<" ";
   for(it1=a.begin();it1!=a.end();it1++)
    cout<<(*it1)<<" ";
   for(it1=b.begin();it1!=b.end();it1++)
    cout<<(*it1)<<" ";

    return 0;
}