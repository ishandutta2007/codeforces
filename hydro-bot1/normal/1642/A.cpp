// Hydro submission #62972c25b0c5e75beb15869d@1654074406235
#include<bits/stdc++.h>
using namespace std;
struct o{
    int x,y;
}a[3];
bool cmp(o p,o q)
{
    return p.y<q.y;
}
int main()
{
    int t,i,j;
    cin>>t;
    for(i=0;i<t;i++)
    {
        for(j=0;j<3;j++)
        cin>>a[j].x>>a[j].y;
        sort(a,a+3,cmp);
        printf("%d\n",a[1].y-a[2].y?0:abs(a[1].x-a[2].x));
    }
    return 0;
}