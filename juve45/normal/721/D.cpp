#include <bits/stdc++.h>

using namespace std;
long long sgn=1, n, k, x, a;
long long s[200009];
priority_queue<pair<long long, long long>, vector <pair<long long, long long> >, greater<pair<long long, long long> > > p;
long long v[200009];
void solve()
{
    pair<long long, long long> pi;
    while(!p.empty() && k>0)
    {
        pi=p.top();
        p.pop();
        pi.first+=x;
        p.push(pi);
        k--;
    }

}

int main()
{
cin>>n>>k>>x;
for(long long i=1;i<=n;i++)
{
    cin>>a;
    if(a<0)
        sgn=-sgn, s[i]=-1;
        else s[i]=1;
    if(a<0) a=-a;
    p.push({a, i});
}
pair<long long, long long> pi;

if(sgn>0)
{
    pi=p.top();
    a=pi.first;
    p.pop();

    while(a>=0 && k)
        a-=x, k--;
if(a<0)
{
    a=-a;
    s[pi.second]=-s[pi.second];
    pi.first=a;
    p.push(pi);
        solve();
}
else {
     pi.first=a;
    p.push(pi);
}

}
else solve();

while(!p.empty())
{
    pi=p.top();
    p.pop();
    v[pi.second]=pi.first;
}

for(long long i=1;i<=n;i++)
{
    cout<<v[i]*s[i]<<' ';
}

    return 0;
}