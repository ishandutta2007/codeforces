#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
bool cmp1(int x,int y)
{
    return s[x]<s[y];
}
bool cmp2(int x,int y)
{
    return s[x]>s[y];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
    cin>>s;
    int n=s.size();
    int ans=2,res=abs(s[n-1]-s[0]);
    vector<int>g;
    for(int i=1;i<n-1;i++)
    {
     int z=abs(s[i]-s[0])+abs(s[i]-s[n-1]);
     if(z==res){ans++;g.push_back(i);}
    }
    cout<<res<<" "<<ans<<endl;
    if(s[n-1]>s[0])sort(g.begin(),g.end(),cmp1);
    else sort(g.begin(),g.end(),cmp2);
    cout<<1<<" ";
    for(int i=0;i<g.size();i++)cout<<g[i]+1<<" ";
    cout<<n<<endl;
    }
    return 0;
}