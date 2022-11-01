#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>v;
long long ans,sum,t[600000],n,q,a[300000];
bool mark[300000];

void ok(int x)
{
    v.clear();
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
        {
            v.push_back(i);
            while(x%i==0)
                x/=i;
        }
    if(x>1)
        v.push_back(x);
}

void eras(int x)
{
    ok(x);
    int sz=v.size();
    ans-=sum;
    for(int i=1;i<(1<<sz);i++)
    {
        int t1=__builtin_popcount(i);
        int y=1;
        for(int j=0;j<v.size();j++)
            if((1<<j)&i)
                y*=v[j];
        t[y]--;
        if(t1%2==1)
            ans+=t[y];
        else
            ans-=t[y];
    }
}

void add(int x)
{
    ok(x);
    int sz=v.size();
    ans+=sum;
    for(int i=1;i<(1<<sz);i++)
    {
        int t1=__builtin_popcount(i);
        int y=1;
        //cout<<"#"<<ans<<endl;
        for(int j=0;j<v.size();j++)
            if((1<<j)&i)
                y*=v[j];
        if(t1%2==1)
            ans-=t[y];
        else
            ans+=t[y];
        t[y]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>n>>q;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<q;i++)
    {
        int x;
        cin>>x;
        x--;
        if(mark[x])
        {
            sum--;
            eras(a[x]);
        }
        else
        {
            add(a[x]);
            sum++;
        }
        mark[x]=1-mark[x];
        cout<<ans<<endl;
    }
}