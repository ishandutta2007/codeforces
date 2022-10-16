#include <iostream>
#include <queue>
using namespace std;

priority_queue <long long> p;
long long n, k;

int main()
{
cin>>n;

for(long long i=1;i<=n;i++)
{
    cin>>k;
    p.push(k);
}

long long x=p.top();
p.pop();
long long l=0;
long long ans=0;
long long ok=0;

while(!p.empty())
{
    long long cr=p.top();
    p.pop();
    if(x-cr<2)
    {
        if(ok==0)
            l=cr, ok=1;
        else
            ans+=l*cr, ok=0;
        if(!p.empty())
        {
        x=p.top();
        p.pop();
        }
    }
    else x=cr;
}
cout<<ans<<'\n';
    return 0;
}