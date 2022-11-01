#include <iostream>
#include<map>
#include<vector>
using namespace std;
vector<int>p;
map<int,int>mi,ma;
long long n,l,r,s1[301000],a[301000],MAX=-1000000000000000000;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(mi.find(a[i])==mi.end())
            mi[a[i]]=i;
        ma[a[i]]=i;
        s1[i]=s1[i-1];
        if(a[i-1]>0)
            s1[i]+=a[i-1];
    }
    for(int i=1;i<=n;i++)
    {
        int x=mi[a[i]],y=ma[a[i]];
        if((s1[y]-s1[x+1]+2*a[i])>MAX && x!=y)
        {
            MAX=s1[y]-s1[x+1]+2*a[i];
            l=x;r=y;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i<l || i>r)
            p.push_back(i);
        if(i>l && i<r && a[i]<0)
            p.push_back(i);
    }
    cout<<MAX<<" "<<p.size()<<endl;
    for(int i=0;i<p.size();i++)
        cout<<p[i]<<" ";
    cout<<endl;
}