#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define x first
#define y second
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    io
    long n,m,l,r,i;
    vl v;
    set < long > a,b,c;
    set < long >::iterator it;
    cin>>n>>m;
    if(m==0) {cout<<n-1;exit(0);}
    for(i=0;i<m;++i)
    {
        cin>>l>>r;
        c.insert(l);
        c.insert(r);
        if(a.find(l)!=a.end() && a.find(r)!=a.end()) {cout<<0;exit(0);}
        if(b.find(l)!=b.end() && b.find(r)!=b.end()) {cout<<0;exit(0);}
        if(l<r) {a.insert(l);b.insert(r);}
        else {a.insert(r);b.insert(l);}
        it=a.end();
        it--;
        if(*b.begin()<*it) {cout<<0;exit(0);}
    }
    for(i=1;i<=n;++i)
    if(a.find(i)!=a.end() && b.find(i)!=b.end()) {cout<<0;exit(0);}
    long cnt=0;
    for(i=1;i<=n;++i)
    if(c.find(i)==c.end()) v.pb(i);
    it=a.end();
    it--;
    for(i=0;i<v.size();++i)
    if(v[i]>*it && *b.begin()>(i?v[i-1]:0)) cnt++;
    if(v.size()==0) {cout<<1;exit(0);}
    if(*b.begin()>max(v[i-1],*it)) cnt++;
    cout<<cnt;
    return 0;
}