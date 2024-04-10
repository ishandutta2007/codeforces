#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int ch[100009],p[100009],sn[100009];
vector<int>a[100008];
int v;
int go(int x,int pr)
{
    ch[x]=1;
    p[x]=pr;
    for(int i=0;i<a[x].size();i++)
        if(a[x][i]!=pr){ch[x]+=go(a[x][i],x);
        sn[x]=a[x][i];}
    return ch[x];

}
int main()
{
    ios::sync_with_stdio(0);
int t;
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    int x,y;
    for(int i=1;i<=n;i++)
    {
        ch[i]=0;
        a[i].clear();
    }
    for(int i=0;i<n-1;i++)
    {
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    
    bool bl=false;
    v=(n)/2;
    go(1,0);
    if(n%2)
    {
        cout<<2<<" "<<p[2]<<endl<<2<<" "<<p[2]<<endl;
        continue;

    }
    for(int i=1;i<=n;i++)
    {
        if(ch[i]==v)
        {
            cout<<i<<" "<<sn[i]<<endl<<sn[i]<<" "<<p[i]<<endl;
            bl=true;
            break;
        }
    }
    if(!bl){
        cout<<2<<" "<<p[2]<<endl<<2<<" "<<p[2]<<endl;}
}
}