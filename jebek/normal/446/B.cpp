#include <iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

long long n,m,k,p,a,sum[2000],sum1[2000],f,flag,ans,ans1;
multiset<long long>s;
vector<long long>v;

int main()
{
    cin>>n>>m>>k>>p;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin>>a;
            sum[i]+=a;
            sum1[j]+=a;
        }
    for(int j=0;j<m;j++)
        s.insert(sum1[j]);
    for(int i=0;i<k;i++)
    {
        f=*(--(s.end()));
        s.erase(--(s.end()));
      //  cout<<"*"<<f<<endl;
        ans+=f;
        v.push_back(f);
        f-=n*p;
        s.insert(f);
    }
    s.clear();
    for(int i=0;i<n;i++)
    {
        sum[i]-=k*p;
        s.insert(sum[i]);
    }
    //cout<<ans<<endl;
    ans1=ans;
    for(int i=1;i<=k;i++)
    {
        flag+=p;
        ans-=v.back();
        v.pop_back();
        f=*(--(s.end()));
        s.erase(--(s.end()));
        ans+=f;
      //  cout<<f<<" "<<flag<<" "<<ans<<endl;
        f-=m*p;
        s.insert(f);
        ans1=max(ans+flag*i,ans1);
    }
    cout<<ans1<<endl;
}