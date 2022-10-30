#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int,int> pii;
vector<pii>ans;
vector<int>v[3];
int n,a;

void check(int k)
{
    int p=0,q=0,r=0,t=0;
    while(p+k<=v[1].size() && q+k<=v[2].size())
    {
        if(v[1][p+k-1]<v[2][q+k-1])
        {
            r++;
            p+=k;
            q=lower_bound(v[2].begin(),v[2].end(),v[1][p-1])-v[2].begin();
        }
        else
        {
            t++;
            q+=k;
            p=lower_bound(v[1].begin(),v[1].end(),v[2][q-1])-v[1].begin();
        }
    //    cout<<p<<" "<<q<<" "<<r<<" "<<t<<endl;
    }
  //  cout<<k<<" "<<p<<" "<<q<<" "<<r<<" "<<t<<endl;
    if(v[1].size()-p<k)
    {
        q=v[2].size()-q;
        if(a==2 && q%k==0)
        {
            t+=q/k;
            if(t>r)
                ans.push_back(pii(t,k));
        }
    }
    else
    {
        p=v[1].size()-p;
        if(a==1 && p%k==0)
        {
            r+=p/k;
            if(t<r)
                ans.push_back(pii(r,k));
        }
    }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        v[a].push_back(i);
    }
    for(int i=1;i<=n;i++)
        check(i);
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
}