#include <iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

typedef pair<int,int> pii;
int n,ans,sum,t;
vector<int>v[100000+100];
vector<pii>v1;
multiset<int>s;

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        ans+=y;
        sum+=y;
    }
    t=n;
    for(int i=1;i<=100000+10;i++)
    {
        sort(v[i].begin(),v[i].end());
        reverse(v[i].begin(),v[i].end());
        if(v[i].size())
            v1.push_back(pii(v[i].size(),i));
    }
    sort(v1.begin(),v1.end());
    int q=0;
    for(int i=0;i<v1.size();i++)
    {
        for(;q<v1[i].first;q++)
        {
            for(int j=i;j<v1.size();j++)
            {
                int ind=v1[j].second;
                sum-=v[ind][q];
                s.insert(v[ind][q]);
                t--;
            }
          //  cout<<sum<<" "<<t<<" "<<q<<" "<<s.size()<<endl;
            while(t<=q+1 && s.size())
            {
    //        cout<<"*";
                t++;
                sum+=*s.begin();
                s.erase(s.begin());
            }
            ans=min(ans,sum);
        }
    }
    cout<<ans<<endl;
}