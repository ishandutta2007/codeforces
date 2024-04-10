// Hydro submission #6290806137e0de7afd399a5b@1653637217783
#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,p;
}m[1000];
bool cmp(node x,node y)
{
    return x.a>y.a;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,k,i;
    cin>>n>>k;
    for(i=0;i<n;i++)
    cin>>m[i].a,m[i].p=i;
    sort(m,m+n,cmp);
    printf("%d\n",m[k-1].a);
    for(i=k;i>0;i--)
    printf("%d ",m[i-1].p+1);
    return 0;
}