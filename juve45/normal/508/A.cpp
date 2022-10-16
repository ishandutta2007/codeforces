#include <iostream>
#define DMAX 1020
using namespace std;

int x[DMAX][DMAX], n, m, k, a, b;

bool check(int a, int b)
{
    if(x[a][b-1]==1 && x[a-1][b-1]==1 && x[a-1][b]==1)
        return true;

    if(x[a][b+1]==1 && x[a-1][b+1]==1 && x[a-1][b]==1)
        return true;

    if(x[a][b-1]==1 && x[a+1][b-1]==1 && x[a+1][b]==1)
        return true;

    if(x[a][b+1]==1 && x[a+1][b+1]==1 && x[a+1][b]==1)
        return true;

    return false;
}

int main()
{
cin>>n>>m>>k;
int ok=0;
for(int i=1;i<=k;i++)
{
    cin>>a>>b;
    x[a][b]=1;
    if(!ok)
    if(check(a, b))
     ok=i;
}
if(ok)
    cout<<ok;
else
cout<<0;
return 0;

    return 0;
}