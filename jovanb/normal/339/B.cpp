#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long n,m,x,oldx,i;
    cin>>n>>m;
    cin>>x;
    long long br=x-1;
    oldx=x;
    for(i=1;i<m;i++){
        cin>>x;
        if(oldx<=x)br+=x-oldx;
        else br+=x-oldx+n;
        oldx=x;
    }
    cout<<br;
    return 0;
}