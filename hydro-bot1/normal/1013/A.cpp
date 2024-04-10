// Hydro submission #625cea4681ef68d42bcba8e5@1650256455474
#include<bits/stdc++.h>
using namespace std;
int sx,sy;
int main()
{
    int n,x,y,i;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>x,sx+=x;
    for(i=0;i<n;i++)
    cin>>y,sy+=y;
    printf(sx<sy?"No\n":"Yes\n");
    return 0;
}