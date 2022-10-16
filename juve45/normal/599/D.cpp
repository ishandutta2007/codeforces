#include <bits/stdc++.h>

using namespace std;

stack <pair<unsigned long long, unsigned long long> > s;
queue <pair<unsigned long long, unsigned long long> > q;
unsigned long long j, x;

bool ok(unsigned long long n)
{
    
    unsigned long long p=3*n*n+3*n;
    unsigned long long g=6*x+n*n*n-n;
    if(g%p!=0)
    {
         j=ceil(g/p);
    if(j<n)
        return false;
        j=-1;
        return true;
    }
    j=g/p;
    if(j<n)
        return false;
    return true;
}

int main()
{
    
cin>>x;

for(unsigned long long i=1;ok(i);i++)
{
    if(j==-1) continue;
    q.push({i, j});
    if(i!=j)
    s.push({j, i});
}

cout<<q.size()+s.size()<<'\n';
while(!q.empty())
{
    pair<unsigned long long, unsigned long long> p=q.front();
    q.pop();
    cout<<p.first<<' '<<p.second<<'\n'; 
}
while(!s.empty())
{
    pair<unsigned long long, unsigned long long> p=s.top();
    s.pop();
    cout<<p.first<<' '<<p.second<<'\n'; 
}

    return 0;
}