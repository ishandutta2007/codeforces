#include <iostream>
#define dmax 1008
using namespace std;

int v[dmax], a, b, n, m;

void print(int k)
{
    cout<<n-1<<'\n';
    for(int i=1;i<=n;i++)
    {
        if(i!=k)
            cout<<i<<' '<<k<<'\n';
    }
}

int main()
{
cin>>n>>m;

for(int i=1;i<=m;i++)
{
    cin>>a>>b;
    v[a]++;
    v[b]++;
}
for(int i=1;i<=n;i++)
{
    if(v[i]==0)
    {
        print(i);
        return 0;
    }
}

}