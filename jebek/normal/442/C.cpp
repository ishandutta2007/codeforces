#include <iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

typedef pair<int,int> pii;
int n,q;
set<int>s;
long long f[1000000],ans,a,b,MAX[3000000],MAX1;
vector<pii>v;

void make(int node,int l,int r)
{
    if(l+1>=r)
    {
        MAX[node]=f[l];
        return;
    }
    int mid=(l+r)/2;
    make(2*node,l,mid);make(2*node+1,mid,r);
    MAX[node]=max(MAX[2*node],MAX[2*node+1]);
}

void f1(int node,int l,int r,int beg,int en)
{
   // q++;
  // if(q<20)
//  cout<<node<<" "<<l<<" "<<r<<" "<<beg<<" "<<en<<" "<<MAX[node]<<endl;
    if(beg<=l && r<=en)
    {
        MAX1=max(MAX1,MAX[node]);
        return;
    }
    int mid=(l+r)/2;
    if(beg<mid) f1(2*node,l,mid,beg,min(en,mid));
    if(mid<en) f1(2*node+1,mid,r,max(mid,beg),en);
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>f[i];
        if(i!=0 && i!=n-1)
            v.push_back(pii(f[i],i));
    }
    make(1,0,n);
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        int k=v[i].second;
     //   cout<<k<<endl;
        set<int>::iterator it=s.upper_bound(k);
        if(it==s.end())
        {
            MAX1=0;
            f1(1,0,n,k+1,n);
            a=MAX1;
        }
        else
            a=f[*it];
        //cout<<"*"<<endl;
        if(it==s.begin())
        {
            MAX1=0;
            f1(1,0,n,0,k);
            b=MAX1;
        }
        else
            b=f[*(--it)];
        //cout<<k<<"*"<<a<<" "<<b<<" "<<f[k]<<endl;
        ans+=min(a,b);
        s.insert(k);
    }
    cout<<ans<<endl;
}