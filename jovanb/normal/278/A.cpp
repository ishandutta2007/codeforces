#include <bits/stdc++.h>

using namespace std;
int cost[105];
int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    int n,z=0,cz=0,a,b,i;
    cin>>n;
    for(i=1;i<=n;i++){cin>>cost[i];z+=cost[i];}
    cin>>a>>b;
    if(a>b)swap(a,b);
    for(i=a;i<b;i++){
        cz+=cost[i];
    }
    cout<<min(cz,z-cz);
    return 0;
}