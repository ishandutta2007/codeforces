// Hydro submission #631f3097bdf9bc31d15c83a2@1662988439741
#include<bits/stdc++.h>
using namespace std;
int p[100001],s;
bool cmp(int x,int y)
{
    return x>y;
}
int main()
{
    int n,d,i;
    cin>>n>>d;
    for(i=1;i<=n;i++)
    cin>>p[i];
    sort(p+1,p+n+1,cmp);
    for(i=1;i<=n;i++)
    {
        s+=d/p[i]+1;
        if(s>n)
        break;
    }
    printf("%d\n",i-1);
    return 0;
}