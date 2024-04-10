#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll d[2][2009],n;
bool ch(ll x)
{
    multiset<ll>s;
    for(int i=0;i<n;i++)s.insert(d[0][i]);
    for(int i=n-1;i>=0;i--)
    {
        multiset<ll>::iterator it=s.find(d[1][i]+x);
        if(it!=s.end()){s.erase(it);continue;}
        if(d[1][i]>=x)it=s.find(d[1][i]-x);
        if(it!=s.end()){s.erase(it);continue;}
        if(d[1][i]<=x)it=s.find(x-d[1][i]);
        if(it!=s.end()){s.erase(it);continue;}
        return false;
    }
    return true;
}
void go(ll x)
{
    cout<<"YES"<<endl;
    multiset<ll>s;
    for(int i=0;i<n;i++)s.insert(d[0][i]);
    vector<int>g;
    for(int i=n-1;i>=0;i--)
    {
        multiset<ll>::iterator it=s.find(d[1][i]+x);
        if(it!=s.end()){g.push_back((*it));s.erase(it);continue;}
        if(d[1][i]>=x)it=s.find(d[1][i]-x);
        if(it!=s.end()){g.push_back((*it));s.erase(it);continue;}
        if(d[1][i]<=x)it=s.find(x-d[1][i]);
        if(it!=s.end()){g.push_back((*it));s.erase(it);continue;}
    }
    reverse(g.begin(),g.end());
    vector<int>h;
    ll r=0;
    for(int i=0;i<n;i++)
    {
        if(d[1][i]+g[i]==x){h.push_back(d[1][i]);continue;}
        if(d[1][i]==x+g[i]){h.push_back(x+g[i]);continue;}
        if(g[i]==x+d[1][i]){h.push_back(-d[1][i]);r=max(r,d[1][i]);continue;}
    }
    for(int i=0;i<n;i++)cout<<h[i]+r<<" ";
    cout<<endl;
    cout<<r+x<<" "<<r<<endl;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
    cin>>n;
    for(int j=0;j<2;j++)
    for(int i=0;i<n;i++)cin>>d[j][i];
    sort(d[0],d[0]+n);
    sort(d[1],d[1]+n);
    bool bl=false;
    for(int i=0;i<n;i++)
    {
        if(ch(d[0][0]+d[1][i])){go(d[0][0]+d[1][i]);bl=true;break;}
        if(ch(abs(d[0][0]-d[1][i]))){go(abs(d[0][0]-d[1][i]));bl=true;break;}
    }
    if(!bl)
    cout<<"NO"<<endl;
    }
    return 0;
}