#include <iostream>
#include <cstdio>
using namespace std;

int n, m, x[1000003];

int main()
{
cin>>n>>m;;

for(int i=1;i<=n;i++)
cin>>x[i];

double vmax=0;

for(int i=1;i<=m;i++)
{
    int a, b, c;
    cin>>a>>b>>c;
    if(vmax<1.0*(x[a]+x[b])/c)
        vmax=1.0*(x[a]+x[b])/c;
}

printf("%.12f\n", vmax);
    return 0;
}