#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cerr.tie(0),cout.tie(0);

    long n,m,a,b,br=0;
    cin>>n>>m;
    for(a=0;a*a<=n;a++){
        b=n-a*a;
        if(a==m-b*b)br++;
    }
    cout<<br;
    return 0;
}