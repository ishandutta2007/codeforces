#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int k;
string s;
int res[2000009];
void go(int x,int st,int en)
{

    if(st==en){res[x]=1;return;}
    int mid=(st+en)/2;
    go(2*x,st,mid);
    go(2*x+1,mid+1,en);
    if(s[x]=='?')res[x]=res[2*x]+res[2*x+1];
    if(s[x]=='1')res[x]=res[2*x];
    if(s[x]=='0') res[x]=res[2*x+1];
}
void ch(int x)
{
    if(x==0)return;
    if(s[x]=='?'){res[x]=res[2*x]+res[2*x+1];ch(x/2);return;}
    if(s[x]=='1')res[x]=res[2*x];
    else res[x]=res[2*x+1];
    ch(x/2);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>k;
    cin>>s;
    s+='#';
    reverse(s.begin(),s.end());
    int z=s.size();
    go(1,1,(1<<k));
    int q;
    cin>>q;
    while(q--)
    {
        int x;
        char c;
        cin>>x>>c;
        s[z-x]=c;
        ch(z-x);
        cout<<res[1]<<endl;
    }
    return 0;
}