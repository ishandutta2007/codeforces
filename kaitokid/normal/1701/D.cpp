#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[500009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector< pair<pair<int,int>,int > >v;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            if(x==0){v.push_back({{i+1,n},i});continue;}
            int u=i/x,g=(i/(x+1))+1;
            v.push_back({{g,u},i});
        }
       sort(v.begin(),v.end());
       set<pair<int,int> >s;
       int j=0;
       for(int i=1;i<=n;i++)
       {
           while((j<n) && (v[j].first.first<=i)){s.insert({v[j].first.second,v[j].second});j++;}
           if(s.empty()){cout<<i<<endl;}
           set<pair<int,int> > ::iterator it=s.begin();

           int u=(*it).second;
           a[u]=i;
           s.erase(it);
       }
       for(int i=1;i<=n;i++)cout<<a[i]<<" ";
       cout<<endl;
    }
    return 0;
}