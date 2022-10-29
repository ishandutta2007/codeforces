#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
long one=-1,zero=-1;
long query(string s)
{
    long x;
    cout<<"? "<<s<<endl;
    fflush(stdout);
    cin>>x;
    return x;
}
void solve(long l,long r,long z,long o,string s,long temp)
{
    if(l==r) {if(z==1) zero=l+1;else one=l+1;return;}
    long mid=(l+r)/2;
    string ss=s;
    for(int i=l;i<=mid;++i)
    s[i]='1';
    long t=query(s);
    long x=(mid+1-l+o+temp-t)/2;
    if(x==mid+1-l)
    {
        if(one==-1) one=l+1;
        solve(mid+1,r,z-(mid+1-l-x),o-x,ss,x+temp);
    }
    else if(x==0)
    {
        if(zero==-1)
        zero=l+1;
        solve(mid+1,r,z-(mid+1-l-x),o-x,ss,x+temp);
    }
    else
    {
        solve(l,mid,mid+1-l-x,x,ss,temp+o-x);
    }
}
int main()
{
    io
    long n;
    cin>>n;
    long lo=0,hi=n,mid;
    string s,ss;
    for(int i=0;i<n;++i)
    s+='0';
    ss=s;
    long t1=query(s);
    for(int i=0;i<n/2;++i)
    ss[i]='1';
    long t2=query(ss);
    long t=(n/2+t1-t2)/2;
    if(t==n/2)
    {
        one=1;
        solve(n/2,n-1,n-n/2-(t1-t),t1-t,s,t);
    }
    else if(t==0)
    {
        zero=1;
        solve(n/2,n-1,n-n/2-(t1-t),t1-t,s,t);
    }
    else solve(0,n/2-1,n/2-t,t,s,t1-t);
    cout<<"! "<<zero<<" "<<one;
    return 0;
}