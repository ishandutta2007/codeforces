#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[2009],n;
int pr[31];
int p(int x)
{
if(pr[x]==x)return x;
return pr[x]=p(pr[x]);
}
bool ch()
{
    for(int i=0;i<30;i++)pr[i]=i;
    int r=0;
    for(int i=0;i<n;i++)
    {
        r|=a[i];
        vector<int>g;
        for(int j=0;j<30;j++)
        {
            if(a[i]&(1<<j))g.push_back(j);
        }
       for(int i=1;i<g.size();i++)
            pr[p(g[i-1])]=p(g[i]);
    }
    int d=-1;
    for(int i=0;i<30;i++)
    {
        if((r&(1<<i))==0)continue;
        int u=p(i);
        if(d==-1){d=u;continue;}
        if(d!=u)return false;
        d=u;

    }
    return true;


}
int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--)
{
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==0){ans++;a[i]=1;}
    }
    if(ch())
    {
        cout<<ans<<endl;
        for(int i=0;i<n;i++)cout<<a[i]<<" ";
        cout<<endl;
        continue;
    }
    bool bl=false;
    for(int i=0;i<n;i++)
    {
        a[i]++;
        if(ch())
        {
            cout<<ans+1<<endl;
            for(int i=0;i<n;i++)cout<<a[i]<<" ";
            cout<<endl;
            bl=true;
            break;
        }
        a[i]--;
        if(a[i]==1)continue;
        a[i]--;
        if(ch())
        {
            cout<<ans+1<<endl;
            for(int i=0;i<n;i++)cout<<a[i]<<" ";
            cout<<endl;
            bl=true;
            break;
        }
        a[i]++;
    }
    if(bl)continue;
    vector<int>g;
    int mx=0;
    for(int i=0;i<n;i++)
    {
        if((a[i]&(-a[i]))>mx){g.clear();mx=(a[i]&(-a[i]));g.push_back(i);continue;}
        if((a[i]&(-a[i]))==mx)g.push_back(i);
    }
    a[g[0]]++;
    a[g[1]]--;
    cout<<ans+2<<endl;
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    cout<<endl;
}

return 0;
}