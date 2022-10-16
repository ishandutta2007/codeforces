#include <bits/stdc++.h>
#define DMAX 200009
using namespace std;

map<int, int> h;
int hmax, a[DMAX], b[DMAX], x, c[DMAX], n;
int m;
int main()
{
cin>>n;

for(int i=1;i<=n;i++)
{
    cin>>x;
    h[x]++;
}
cin>>m;
for(int i=1;i<=m;i++)
{
    cin>>x;
    int c=h[x];
    a[i]=c;
    if(c>hmax) hmax=c;
}
for(int i=1;i<=m;i++)
{
    cin>>x;
    b[i]=h[x];
}
int imax=0;
for(int i=1;i<=m;i++)
{
    if(a[i]==hmax)
    {
        if(b[i]>b[imax] || imax==0)
        {
            imax=i;
        }
    }
}

cout<<imax<<'\n';


    return 0;
}