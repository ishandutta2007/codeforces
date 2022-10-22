#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,g,h;
vector<int>ed[200009];
int pr[200009];
int go(int x,int p)
{
    int d=0;
    for(int i=0;i<ed[x].size();i++)
           d=max(d,go(ed[x][i],x));
    d++;
    if((d==h)&&(p!=1)&&(x!=1)){g++;d=0;}
    return d;

}
bool ch(int x)
{
    g=0;
    h=x;
    go(1,0);
    //cout<<x<<" "<<g<<endl;
    return (g<=k);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
       cin>>n>>k;
       for(int i=0;i<=n;i++)ed[i].clear();
       for(int i=2;i<=n;i++)
       {
           cin>>pr[i];
           ed[pr[i]].push_back(i);
       }
       int l=1,r=n;
       while(l<r)
       {
           int mid=(l+r)/2;
           if(ch(mid))r=mid;
           else l=mid+1;
       }
       cout<<l<<endl;

    }
    return 0;
}