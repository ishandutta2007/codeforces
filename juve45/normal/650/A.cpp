#include <iostream>
#include <map>
using namespace std;

int n, A, B;
map <int, int> x, y;
map < pair<int, int> , int> z;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>A>>B;
        x[A]++;
        y[B]++;
        z[{A, B}]++;
    }
long long ans=0;
map<int, int> :: iterator it;
for(it=x.begin();it!=x.end();it++)
{
    int k=it->second;
    ans+=(long long) k*(k-1)/2;
}

for(it=y.begin();it!=y.end();it++)
{
    int k=it->second;
    ans+=(long long)k*(k-1)/2;
}


map <pair<int, int>, int> :: iterator it2;

for(it2=z.begin();it2!=z.end();it2++)
{
    int k=it2->second;
    ans-=(long long)k*(k-1)/2;
}

cout<<ans<<'\n';

    return 0;
}